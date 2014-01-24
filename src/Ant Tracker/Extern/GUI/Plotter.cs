using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace GUI
{
    public partial class PlotterFrame : Form
    {
        public PlotterFrame() {
            InitializeComponent();
        }

        private void BtnGo_Click(object sender, EventArgs e)
        {
            int x = int.Parse(txtX.Text);
            int y = int.Parse(txtY.Text);

            Connector.GoToCoordinate(ref x, ref y);
        }

        private void BtnDown_Click(object sender, EventArgs e)
        {
            int deltaX = int.Parse(txtStepX.Text) * -1;
            int deltaY = 0;

            Connector.MovePlotter(ref deltaX, ref deltaY);
            UpdateXY();
        }

        private void BtnUp_Click(object sender, EventArgs e)
        {
            int deltaX = int.Parse(txtStepX.Text);
            int deltaY = 0;

            Connector.MovePlotter(ref deltaX, ref deltaY);
            UpdateXY();
        }

        private void BtnRight_Click(object sender, EventArgs e)
        {
            int deltaX = 0;
            int deltaY = int.Parse(txtStepY.Text) * -1;

            Connector.MovePlotter(ref deltaX, ref deltaY);
            UpdateXY();
        }

        private void BtnLeft_Click(object sender, EventArgs e)
        {
            int deltaX = 0;
            int deltaY = int.Parse(txtStepY.Text);

            Connector.MovePlotter(ref deltaX, ref deltaY);
            UpdateXY();
        }

        private void UpdateXY() 
        {
            int x = 0, y = 0;
            Connector.GetPlotterLocation(ref x, ref y);
            txtX.Text = x + "";
            txtY.Text = y + "";
        }
    }
}
