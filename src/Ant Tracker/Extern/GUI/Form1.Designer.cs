namespace GUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.videoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.startToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stopToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.plotterToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.manualSteeringToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.modeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.workingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.calibrationToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.trackingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.startTrackingToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.start = new System.Windows.Forms.ToolStripMenuItem();
            this.autolocateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stopTrackingToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.leftGroupBox = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.statisticsPanel = new System.Windows.Forms.Panel();
            this.groupbox = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.BtnChangeHeatmapColor = new System.Windows.Forms.Button();
            this.lblColorHeatmap = new System.Windows.Forms.Label();
            this.lblColorKeypoints = new System.Windows.Forms.Label();
            this.BtnChangeKeypointsColor = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.chckHeatmap = new System.Windows.Forms.CheckBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.cmbKeypoints = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.lblFrameProcessingTime = new System.Windows.Forms.Label();
            this.lblAvgProcessingTime = new System.Windows.Forms.Label();
            this.lblActualProcessingTime = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.rightGroupBox = new System.Windows.Forms.GroupBox();
            this.BtnStopScan = new System.Windows.Forms.Button();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.slidersPanel = new System.Windows.Forms.Panel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.lblThreshold = new System.Windows.Forms.Label();
            this.trckThreshold = new System.Windows.Forms.TrackBar();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.leftGroupBox.SuspendLayout();
            this.statisticsPanel.SuspendLayout();
            this.groupbox.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.rightGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.slidersPanel.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trckThreshold)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(29, 38);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(640, 480);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.videoToolStripMenuItem,
            this.plotterToolStripMenuItem,
            this.modeToolStripMenuItem,
            this.trackingToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(8, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(1448, 28);
            this.menuStrip1.TabIndex = 2;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(44, 24);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(102, 24);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // videoToolStripMenuItem
            // 
            this.videoToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.startToolStripMenuItem,
            this.stopToolStripMenuItem});
            this.videoToolStripMenuItem.Name = "videoToolStripMenuItem";
            this.videoToolStripMenuItem.Size = new System.Drawing.Size(60, 24);
            this.videoToolStripMenuItem.Text = "Video";
            // 
            // startToolStripMenuItem
            // 
            this.startToolStripMenuItem.Name = "startToolStripMenuItem";
            this.startToolStripMenuItem.Size = new System.Drawing.Size(109, 24);
            this.startToolStripMenuItem.Text = "Start";
            this.startToolStripMenuItem.Click += new System.EventHandler(this.Track);
            // 
            // stopToolStripMenuItem
            // 
            this.stopToolStripMenuItem.Name = "stopToolStripMenuItem";
            this.stopToolStripMenuItem.Size = new System.Drawing.Size(109, 24);
            this.stopToolStripMenuItem.Text = "Stop";
            this.stopToolStripMenuItem.Click += new System.EventHandler(this.stopToolStripMenuItem_Click);
            // 
            // plotterToolStripMenuItem
            // 
            this.plotterToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.manualSteeringToolStripMenuItem});
            this.plotterToolStripMenuItem.Name = "plotterToolStripMenuItem";
            this.plotterToolStripMenuItem.Size = new System.Drawing.Size(65, 24);
            this.plotterToolStripMenuItem.Text = "Plotter";
            // 
            // manualSteeringToolStripMenuItem
            // 
            this.manualSteeringToolStripMenuItem.Name = "manualSteeringToolStripMenuItem";
            this.manualSteeringToolStripMenuItem.Size = new System.Drawing.Size(186, 24);
            this.manualSteeringToolStripMenuItem.Text = "Manual Steering";
            this.manualSteeringToolStripMenuItem.Click += new System.EventHandler(this.manualSteeringToolStripMenuItem_Click);
            // 
            // modeToolStripMenuItem
            // 
            this.modeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.workingToolStripMenuItem,
            this.calibrationToolStripMenuItem1});
            this.modeToolStripMenuItem.Name = "modeToolStripMenuItem";
            this.modeToolStripMenuItem.Size = new System.Drawing.Size(60, 24);
            this.modeToolStripMenuItem.Text = "Mode";
            // 
            // workingToolStripMenuItem
            // 
            this.workingToolStripMenuItem.Name = "workingToolStripMenuItem";
            this.workingToolStripMenuItem.Size = new System.Drawing.Size(194, 24);
            this.workingToolStripMenuItem.Text = "Working Mode";
            this.workingToolStripMenuItem.Click += new System.EventHandler(this.workingToolStripMenuItem_Click);
            // 
            // calibrationToolStripMenuItem1
            // 
            this.calibrationToolStripMenuItem1.Name = "calibrationToolStripMenuItem1";
            this.calibrationToolStripMenuItem1.Size = new System.Drawing.Size(194, 24);
            this.calibrationToolStripMenuItem1.Text = "Calibration Mode";
            this.calibrationToolStripMenuItem1.Click += new System.EventHandler(this.calibrationToolStripMenuItem1_Click);
            // 
            // trackingToolStripMenuItem
            // 
            this.trackingToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.startTrackingToolStripMenuItem1,
            this.stopTrackingToolStripMenuItem1});
            this.trackingToolStripMenuItem.Name = "trackingToolStripMenuItem";
            this.trackingToolStripMenuItem.Size = new System.Drawing.Size(77, 24);
            this.trackingToolStripMenuItem.Text = "Tracking";
            // 
            // startTrackingToolStripMenuItem1
            // 
            this.startTrackingToolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.start,
            this.autolocateToolStripMenuItem});
            this.startTrackingToolStripMenuItem1.Name = "startTrackingToolStripMenuItem1";
            this.startTrackingToolStripMenuItem1.Size = new System.Drawing.Size(109, 24);
            this.startTrackingToolStripMenuItem1.Text = "Start";
            // 
            // start
            // 
            this.start.Name = "start";
            this.start.Size = new System.Drawing.Size(151, 24);
            this.start.Text = "Start";
            this.start.Click += new System.EventHandler(this.start_Click);
            // 
            // autolocateToolStripMenuItem
            // 
            this.autolocateToolStripMenuItem.Name = "autolocateToolStripMenuItem";
            this.autolocateToolStripMenuItem.Size = new System.Drawing.Size(151, 24);
            this.autolocateToolStripMenuItem.Text = "Autolocate";
            this.autolocateToolStripMenuItem.Click += new System.EventHandler(this.autolocateToolStripMenuItem_Click);
            // 
            // stopTrackingToolStripMenuItem1
            // 
            this.stopTrackingToolStripMenuItem1.Name = "stopTrackingToolStripMenuItem1";
            this.stopTrackingToolStripMenuItem1.Size = new System.Drawing.Size(109, 24);
            this.stopTrackingToolStripMenuItem1.Text = "Stop";
            this.stopTrackingToolStripMenuItem1.Click += new System.EventHandler(this.stopTrackingToolStripMenuItem1_Click);
            // 
            // leftGroupBox
            // 
            this.leftGroupBox.Controls.Add(this.label5);
            this.leftGroupBox.Controls.Add(this.pictureBox1);
            this.leftGroupBox.Location = new System.Drawing.Point(16, 46);
            this.leftGroupBox.Margin = new System.Windows.Forms.Padding(4);
            this.leftGroupBox.Name = "leftGroupBox";
            this.leftGroupBox.Padding = new System.Windows.Forms.Padding(4);
            this.leftGroupBox.Size = new System.Drawing.Size(699, 577);
            this.leftGroupBox.TabIndex = 3;
            this.leftGroupBox.TabStop = false;
            this.leftGroupBox.Text = "Raw Video Feed";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(31, 529);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(12, 17);
            this.label5.TabIndex = 7;
            this.label5.Text = " ";
            // 
            // statisticsPanel
            // 
            this.statisticsPanel.Controls.Add(this.groupbox);
            this.statisticsPanel.Location = new System.Drawing.Point(3, 627);
            this.statisticsPanel.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.statisticsPanel.Name = "statisticsPanel";
            this.statisticsPanel.Size = new System.Drawing.Size(1459, 263);
            this.statisticsPanel.TabIndex = 8;
            // 
            // groupbox
            // 
            this.groupbox.Controls.Add(this.groupBox4);
            this.groupbox.Controls.Add(this.groupBox2);
            this.groupbox.Controls.Add(this.groupBox1);
            this.groupbox.Location = new System.Drawing.Point(16, 4);
            this.groupbox.Margin = new System.Windows.Forms.Padding(4);
            this.groupbox.Name = "groupbox";
            this.groupbox.Padding = new System.Windows.Forms.Padding(4);
            this.groupbox.Size = new System.Drawing.Size(1411, 247);
            this.groupbox.TabIndex = 6;
            this.groupbox.TabStop = false;
            this.groupbox.Text = "Statistics";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.BtnChangeHeatmapColor);
            this.groupBox4.Controls.Add(this.lblColorHeatmap);
            this.groupBox4.Controls.Add(this.lblColorKeypoints);
            this.groupBox4.Controls.Add(this.BtnChangeKeypointsColor);
            this.groupBox4.Controls.Add(this.label4);
            this.groupBox4.Controls.Add(this.label3);
            this.groupBox4.Location = new System.Drawing.Point(353, 35);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(449, 191);
            this.groupBox4.TabIndex = 6;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Colors";
            // 
            // BtnChangeHeatmapColor
            // 
            this.BtnChangeHeatmapColor.Location = new System.Drawing.Point(249, 72);
            this.BtnChangeHeatmapColor.Name = "BtnChangeHeatmapColor";
            this.BtnChangeHeatmapColor.Size = new System.Drawing.Size(94, 23);
            this.BtnChangeHeatmapColor.TabIndex = 19;
            this.BtnChangeHeatmapColor.Text = "Change";
            this.BtnChangeHeatmapColor.UseVisualStyleBackColor = true;
            this.BtnChangeHeatmapColor.Click += new System.EventHandler(this.BtnChangeHeatmapColor_Click);
            // 
            // lblColorHeatmap
            // 
            this.lblColorHeatmap.AutoSize = true;
            this.lblColorHeatmap.Location = new System.Drawing.Point(107, 75);
            this.lblColorHeatmap.Name = "lblColorHeatmap";
            this.lblColorHeatmap.Size = new System.Drawing.Size(0, 17);
            this.lblColorHeatmap.TabIndex = 18;
            // 
            // lblColorKeypoints
            // 
            this.lblColorKeypoints.AutoSize = true;
            this.lblColorKeypoints.Location = new System.Drawing.Point(107, 46);
            this.lblColorKeypoints.Name = "lblColorKeypoints";
            this.lblColorKeypoints.Size = new System.Drawing.Size(0, 17);
            this.lblColorKeypoints.TabIndex = 17;
            // 
            // BtnChangeKeypointsColor
            // 
            this.BtnChangeKeypointsColor.Location = new System.Drawing.Point(249, 43);
            this.BtnChangeKeypointsColor.Name = "BtnChangeKeypointsColor";
            this.BtnChangeKeypointsColor.Size = new System.Drawing.Size(94, 23);
            this.BtnChangeKeypointsColor.TabIndex = 16;
            this.BtnChangeKeypointsColor.Text = "Change";
            this.BtnChangeKeypointsColor.UseVisualStyleBackColor = true;
            this.BtnChangeKeypointsColor.Click += new System.EventHandler(this.BtnChangeKeypointsColor_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(19, 75);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 17);
            this.label4.TabIndex = 14;
            this.label4.Text = "Heatmap";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(19, 46);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(70, 17);
            this.label3.TabIndex = 13;
            this.label3.Text = "Keypoints";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.chckHeatmap);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.cmbKeypoints);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Location = new System.Drawing.Point(25, 35);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(322, 191);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Statistics";
            // 
            // chckHeatmap
            // 
            this.chckHeatmap.AutoSize = true;
            this.chckHeatmap.Checked = true;
            this.chckHeatmap.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chckHeatmap.Location = new System.Drawing.Point(141, 74);
            this.chckHeatmap.Name = "chckHeatmap";
            this.chckHeatmap.Size = new System.Drawing.Size(18, 17);
            this.chckHeatmap.TabIndex = 12;
            this.chckHeatmap.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(19, 75);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(103, 17);
            this.label2.TabIndex = 11;
            this.label2.Text = "Show Heatmap";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(207, 46);
            this.label9.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(68, 17);
            this.label9.TabIndex = 10;
            this.label9.Text = "keypoints";
            // 
            // cmbKeypoints
            // 
            this.cmbKeypoints.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbKeypoints.FormattingEnabled = true;
            this.cmbKeypoints.Items.AddRange(new object[] {
            "50",
            "100",
            "200",
            "300",
            "400",
            "500",
            "600",
            "700",
            "800",
            "900",
            "1000"});
            this.cmbKeypoints.Location = new System.Drawing.Point(141, 43);
            this.cmbKeypoints.Margin = new System.Windows.Forms.Padding(4);
            this.cmbKeypoints.Name = "cmbKeypoints";
            this.cmbKeypoints.Size = new System.Drawing.Size(58, 24);
            this.cmbKeypoints.TabIndex = 8;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(19, 46);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(68, 17);
            this.label7.TabIndex = 9;
            this.label7.Text = "Show last";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.lblFrameProcessingTime);
            this.groupBox1.Controls.Add(this.lblAvgProcessingTime);
            this.groupBox1.Controls.Add(this.lblActualProcessingTime);
            this.groupBox1.Controls.Add(this.label13);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Location = new System.Drawing.Point(808, 35);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(573, 191);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Performance";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 86);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(164, 17);
            this.label1.TabIndex = 4;
            this.label1.Text = "Actual Processing Time: ";
            // 
            // lblFrameProcessingTime
            // 
            this.lblFrameProcessingTime.AutoSize = true;
            this.lblFrameProcessingTime.Location = new System.Drawing.Point(202, 36);
            this.lblFrameProcessingTime.Name = "lblFrameProcessingTime";
            this.lblFrameProcessingTime.Size = new System.Drawing.Size(0, 17);
            this.lblFrameProcessingTime.TabIndex = 3;
            // 
            // lblAvgProcessingTime
            // 
            this.lblAvgProcessingTime.AutoSize = true;
            this.lblAvgProcessingTime.Location = new System.Drawing.Point(202, 60);
            this.lblAvgProcessingTime.Name = "lblAvgProcessingTime";
            this.lblAvgProcessingTime.Size = new System.Drawing.Size(0, 17);
            this.lblAvgProcessingTime.TabIndex = 1;
            // 
            // lblActualProcessingTime
            // 
            this.lblActualProcessingTime.AutoSize = true;
            this.lblActualProcessingTime.Location = new System.Drawing.Point(202, 86);
            this.lblActualProcessingTime.Name = "lblActualProcessingTime";
            this.lblActualProcessingTime.Size = new System.Drawing.Size(0, 17);
            this.lblActualProcessingTime.TabIndex = 5;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(18, 60);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(178, 17);
            this.label13.TabIndex = 2;
            this.label13.Text = "Average Processing Time: ";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(18, 36);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(165, 17);
            this.label12.TabIndex = 1;
            this.label12.Text = "Frame Processing Time: ";
            // 
            // rightGroupBox
            // 
            this.rightGroupBox.Controls.Add(this.BtnStopScan);
            this.rightGroupBox.Controls.Add(this.pictureBox2);
            this.rightGroupBox.Location = new System.Drawing.Point(731, 46);
            this.rightGroupBox.Margin = new System.Windows.Forms.Padding(4);
            this.rightGroupBox.Name = "rightGroupBox";
            this.rightGroupBox.Padding = new System.Windows.Forms.Padding(4);
            this.rightGroupBox.Size = new System.Drawing.Size(691, 577);
            this.rightGroupBox.TabIndex = 4;
            this.rightGroupBox.TabStop = false;
            this.rightGroupBox.Text = "Threshold Feed";
            // 
            // BtnStopScan
            // 
            this.BtnStopScan.Enabled = false;
            this.BtnStopScan.Location = new System.Drawing.Point(29, 529);
            this.BtnStopScan.Name = "BtnStopScan";
            this.BtnStopScan.Size = new System.Drawing.Size(123, 28);
            this.BtnStopScan.TabIndex = 2;
            this.BtnStopScan.Text = "Stop Scanning";
            this.BtnStopScan.UseVisualStyleBackColor = true;
            this.BtnStopScan.Click += new System.EventHandler(this.BtnStopScan_Click);
            // 
            // pictureBox2
            // 
            this.pictureBox2.Location = new System.Drawing.Point(29, 38);
            this.pictureBox2.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(640, 480);
            this.pictureBox2.TabIndex = 1;
            this.pictureBox2.TabStop = false;
            // 
            // slidersPanel
            // 
            this.slidersPanel.Controls.Add(this.groupBox3);
            this.slidersPanel.Location = new System.Drawing.Point(0, 629);
            this.slidersPanel.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.slidersPanel.Name = "slidersPanel";
            this.slidersPanel.Size = new System.Drawing.Size(1459, 263);
            this.slidersPanel.TabIndex = 7;
            this.slidersPanel.Visible = false;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.lblThreshold);
            this.groupBox3.Controls.Add(this.trckThreshold);
            this.groupBox3.Location = new System.Drawing.Point(13, 4);
            this.groupBox3.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox3.Size = new System.Drawing.Size(1409, 247);
            this.groupBox3.TabIndex = 5;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Range From";
            // 
            // lblThreshold
            // 
            this.lblThreshold.AutoSize = true;
            this.lblThreshold.Location = new System.Drawing.Point(1339, 44);
            this.lblThreshold.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblThreshold.Name = "lblThreshold";
            this.lblThreshold.Size = new System.Drawing.Size(16, 17);
            this.lblThreshold.TabIndex = 11;
            this.lblThreshold.Text = "0";
            // 
            // trckThreshold
            // 
            this.trckThreshold.Location = new System.Drawing.Point(20, 42);
            this.trckThreshold.Margin = new System.Windows.Forms.Padding(4);
            this.trckThreshold.Maximum = 255;
            this.trckThreshold.Name = "trckThreshold";
            this.trckThreshold.Size = new System.Drawing.Size(1311, 56);
            this.trckThreshold.TabIndex = 7;
            this.trckThreshold.TickFrequency = 5;
            this.trckThreshold.ValueChanged += new System.EventHandler(this.trckThreshold_ValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1448, 897);
            this.Controls.Add(this.statisticsPanel);
            this.Controls.Add(this.slidersPanel);
            this.Controls.Add(this.leftGroupBox);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.rightGroupBox);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "TERMES Termite Tracker v.0.1 (Beta)";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.leftGroupBox.ResumeLayout(false);
            this.leftGroupBox.PerformLayout();
            this.statisticsPanel.ResumeLayout(false);
            this.groupbox.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.rightGroupBox.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.slidersPanel.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trckThreshold)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.GroupBox leftGroupBox;
        private System.Windows.Forms.GroupBox rightGroupBox;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.ToolStripMenuItem videoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem startToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem stopToolStripMenuItem;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ToolStripMenuItem plotterToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem manualSteeringToolStripMenuItem;
        private System.Windows.Forms.Panel slidersPanel;
        private System.Windows.Forms.ToolStripMenuItem modeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem workingToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem calibrationToolStripMenuItem1;
        private System.Windows.Forms.Panel statisticsPanel;
        private System.Windows.Forms.GroupBox groupbox;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox cmbKeypoints;
        private System.Windows.Forms.ToolStripMenuItem trackingToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem startTrackingToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem stopTrackingToolStripMenuItem1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label lblFrameProcessingTime;
        private System.Windows.Forms.Label lblAvgProcessingTime;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label lblThreshold;
        private System.Windows.Forms.TrackBar trckThreshold;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblActualProcessingTime;
        private System.Windows.Forms.CheckBox chckHeatmap;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button BtnChangeKeypointsColor;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Button BtnChangeHeatmapColor;
        private System.Windows.Forms.Label lblColorHeatmap;
        private System.Windows.Forms.Label lblColorKeypoints;
        private System.Windows.Forms.ToolStripMenuItem start;
        private System.Windows.Forms.ToolStripMenuItem autolocateToolStripMenuItem;
        private System.Windows.Forms.Button BtnStopScan;
    }
}

