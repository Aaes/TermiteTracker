using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Threading;
using System.Diagnostics;
using System.Drawing.Drawing2D;

namespace GUI
{
    public partial class Form1 : Form
    {
        string frameTitle = "TERMES Termite Tracker v.0.1 (Beta)";

        byte[] buffer1 = new byte[921600];
        byte[] buffer2 = new byte[921600];
        int[] heatmap  = new int[400];

        Thread cameras;
        readonly object switchModeLock = new object { };
        readonly object colorLock = new object { };

        volatile bool calibrationMode = false;
        volatile bool run = false;
        volatile bool tracking = false;

        Color heatmapColor = Color.Red;
        Color keypointsColor = Color.Orange;

        public Form1() {
            InitializeComponent();
            cmbKeypoints.SelectedIndex = 0;

            lblColorKeypoints.Text = string.Format("({0}, {1}, {2})", keypointsColor.R, keypointsColor.G, keypointsColor.B);
            lblColorHeatmap.Text = string.Format("({0}, {1}, {2})", heatmapColor.R, heatmapColor.G, heatmapColor.B);

            Connector.StartUp();
            RunCameras();
        }

        private void ReDrawFrames() {
            pictureBox1.Image = ConvertBuffer1();
            pictureBox2.Image = ConvertBuffer2();
        }

        public Bitmap ConvertBuffer1() {
            Connector.MobileCamera(buffer1);

            //Convert buffer to bitmap
            Bitmap bmp = new Bitmap(640, 480);
            var data = bmp.LockBits(new Rectangle(Point.Empty, bmp.Size), System.Drawing.Imaging.ImageLockMode.WriteOnly, System.Drawing.Imaging.PixelFormat.Format24bppRgb);
            Marshal.Copy(buffer1, 0, data.Scan0, buffer1.Length);
            bmp.UnlockBits(data);

            //Draw center of frame
            int middleX = 320;
            int middleY = 240;
            using (Graphics g = Graphics.FromImage(bmp)) {
                using (Pen p = new Pen(Color.Red)) {
                    g.DrawLine(p, new Point(middleX, middleY - 5), new Point(middleX, middleY + 5));
                    g.DrawLine(p, new Point(middleX - 5, middleY), new Point(middleX + 5, middleY));
                }
            }

            if (tracking) {
                //Get ant position
                int x = 0, y = 0, size = 0;
                Connector.GetAntPosition(ref x, ref y, ref size);

                using (Graphics g = Graphics.FromImage(bmp)) {
                    using (Pen p = new Pen(Color.Red)) {
                        g.DrawEllipse(p, x - 10, y - 10, 20, 20);
                    }
                }
            }

            return bmp;
        }

        public Bitmap ConvertBuffer2() {
            if (calibrationMode) {
                Connector.ThresholdMobileCamera(buffer2);
            } else {
                Connector.OverheadCamera(buffer2);
            }

            Bitmap bmp = new Bitmap(640, 480);
            var data = bmp.LockBits(new Rectangle(Point.Empty, bmp.Size), System.Drawing.Imaging.ImageLockMode.WriteOnly, calibrationMode ? System.Drawing.Imaging.PixelFormat.Format8bppIndexed : System.Drawing.Imaging.PixelFormat.Format24bppRgb);
            Marshal.Copy(buffer2, 0, data.Scan0, buffer2.Length);
            bmp.UnlockBits(data);

            if (tracking) {
                using (Graphics g = Graphics.FromImage(bmp)) 
                {
                    //Get the last X ant locations
                    int numberOfKeypoints = int.Parse(cmbKeypoints.SelectedItem.ToString());
                    if (numberOfKeypoints > 0) {
                        int[] xs = new int[numberOfKeypoints];
                        int[] ys = new int[numberOfKeypoints];
                        Connector.GetKeyPoints(xs, ys, numberOfKeypoints);

                        lock (colorLock) {
                            using (Pen p = new Pen(keypointsColor)) {
                                for (int i = 0; i < numberOfKeypoints; i++) {
                                    g.DrawEllipse(p, xs[i] - 5, ys[i] - 5, 10, 10);
                                }
                            }
                        }
                    }

                    //Draw heatmap
                    if (chckHeatmap.Checked && !calibrationMode) {
                        Connector.GetHeatMap(heatmap);

                        //White background
                        g.FillRectangle(new SolidBrush(Color.FromArgb(60, 255, 255, 255)), new Rectangle(160, 144, 288, 240));

                        lock (colorLock) {
                            for (int i = 5; i < 14; i++) {
                                for (int j = 6; j < 16; j++) {
                                    Color fence = Color.FromArgb(50, heatmapColor.R, heatmapColor.G, heatmapColor.B);
                                    Color heat = Color.FromArgb(heatmap[i * 20 + j] > 255 ? 255 : heatmap[i * 20 + j], heatmapColor.R, heatmapColor.G, heatmapColor.B);

                                    g.DrawRectangle(new Pen(fence), new Rectangle(i * 32, j * 24, 32, 24));
                                    g.FillRectangle(new SolidBrush(heat), new Rectangle(i * 32, j * 24, 32, 24));
                                }
                            }
                        }
                    }
                }


            }

            return bmp;
        }

        private void RunCameras() {
            run = true;
            cameras = new Thread(() => {
                while (run) {
                    int frameProcessingTime = 0, actualProcessingTime = 0, averageProcessingTime = 0;
                    Connector.NextFrame(trckThreshold.Value, ref frameProcessingTime, ref actualProcessingTime, ref averageProcessingTime);
                    ReDrawFrames();

                    lblFrameProcessingTime.Text = frameProcessingTime + " ms";
                    lblActualProcessingTime.Text = actualProcessingTime + " ms";
                    lblAvgProcessingTime.Text = averageProcessingTime + " ms";
                }
            });
            cameras.Start();
        }

        private void Track(object sender, EventArgs e) {
            tracking = true;
        }

        private void stopToolStripMenuItem_Click(object sender, EventArgs e) {
            tracking = false;
        }

        private void trckThreshold_ValueChanged(object sender, EventArgs e) {
            lblThreshold.Text = trckThreshold.Value + "";
        }

        private void manualSteeringToolStripMenuItem_Click(object sender, EventArgs e) {
            new PlotterFrame().Show();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e) {
            try {
                run = false;

                if (cameras != null && cameras.ThreadState == System.Threading.ThreadState.Running)
                    cameras.Join();

                Connector.ShutDown();
                Application.Exit();
            } catch (Exception ex) {
                label5.Text = ex.Message + ", InnerException: " + ex.InnerException == null ? "" : ex.InnerException.Message;
            }
        }

        private void workingToolStripMenuItem_Click(object sender, EventArgs e) {
            switchMode(false);
            this.Text = frameTitle + " (Working Mode)";
            rightGroupBox.Text = "Overhead Feed";
            slidersPanel.Visible = false;
            statisticsPanel.Visible = true;
            statisticsPanel.BringToFront();
            statisticsPanel.Show();
        }

        private void calibrationToolStripMenuItem1_Click(object sender, EventArgs e) {
            switchMode(true);
            this.Text = frameTitle + " (Calibration Mode)";
            rightGroupBox.Text = "Threshold Feed";
            slidersPanel.Visible = true;
            statisticsPanel.Visible = false;
            slidersPanel.BringToFront();
            slidersPanel.Show();
        }

        private void switchMode(bool calibration) {
            lock (switchModeLock) {
                if (calibration) {
                    buffer2 = new byte[307200];
                } else {
                    buffer2 = new byte[921600];
                }
                calibrationMode = calibration;
            }
        }

        private void stopTrackingToolStripMenuItem1_Click(object sender, EventArgs e) {
            tracking = false;
            Connector.StopTracking();
        }

        private void BtnChangeKeypointsColor_Click(object sender, EventArgs e) {
            DialogResult result = colorDialog1.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK) {
                lock (colorLock) {
                    keypointsColor = colorDialog1.Color;
                    lblColorKeypoints.Text = string.Format("({0}, {1}, {2})", keypointsColor.R, keypointsColor.G, keypointsColor.B);
                }
            }
        }

        private void BtnChangeHeatmapColor_Click(object sender, EventArgs e) {
            DialogResult result = colorDialog1.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK) {
                lock (colorLock) {
                    heatmapColor = colorDialog1.Color;
                    lblColorHeatmap.Text = string.Format("({0}, {1}, {2})", heatmapColor.R, heatmapColor.G, heatmapColor.B);
                }
            }
        }

        private void start_Click(object sender, EventArgs e) {
            Connector.StartTracking();
            tracking = true;
        }

        private void autolocateToolStripMenuItem_Click(object sender, EventArgs e) {
            BtnStopScan.Enabled = true;
            new Thread(() => {
                Again:
                    bool success = false;
                    Connector.Scan(trckThreshold.Value, ref success);

                    if (success) {
                        BtnStopScan.Enabled = false;
                        Connector.StartTracking();
                        tracking = true;
                    } else {
                        DialogResult dr = MessageBox.Show("Did not find ant. Try again?", "Done", MessageBoxButtons.YesNo);
                        if (dr == System.Windows.Forms.DialogResult.Yes) {
                            goto Again;
                        } else {
                            BtnStopScan.Enabled = false;
                        }
                    }
            }).Start();
        }

        private void BtnStopScan_Click(object sender, EventArgs e) {
            Connector.StopScanning();
            BtnStopScan.Enabled = false;
        }
    }


    class Connector
    {
        [DllImport("../../../Release/Extern.dll")]
        public static extern void GoToCoordinate(ref int x, ref int y);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void MovePlotter(ref int deltaX, ref int deltaY);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void GetPlotterLocation(ref int x, ref int y);         //Returns (0,0) until the plotter has been programatically moved

        [DllImport("../../../Release/Extern.dll")]
        public static extern void GetKeyPoints(int[] xs, int[] ys, int count);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void Scan(int threshold, ref bool success);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void GetAntPosition(ref int x, ref int y, ref int size);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void NextFrame(int threshold,
                                            ref int frameTime,
                                            ref int processingTime,
                                            ref int averageProcessingTime);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void MobileCamera(byte[] buffer);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void OverheadCamera(byte[] buffer);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void ThresholdMobileCamera(byte[] buffer);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void GetHeatMap(int[] map);

        [DllImport("../../../Release/Extern.dll")]
        public static extern void StartUp();

        [DllImport("../../../Release/Extern.dll")]
        public static extern void ShutDown();

        [DllImport("../../../Release/Extern.dll")]
        public static extern void StartTracking();

        [DllImport("../../../Release/Extern.dll")]
        public static extern void StopTracking();

        [DllImport("../../../Release/Extern.dll")]
        public static extern void StopScanning();
    }
}