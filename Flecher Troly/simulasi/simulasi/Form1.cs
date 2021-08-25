using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace simulasi
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

       
        string[] portNames = System.IO.Ports.SerialPort.GetPortNames();
        string terima, buffer, sensor1, sensor2, waktu, m1, m2, m3, rly;
        LeftRightMid ambil = new LeftRightMid();
       
        private void Form1_Load(object sender, EventArgs e)
        {
            serial.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(DataReceived);
            for (int i = 0; i <= portNames.Length - 1; i++)
            {

                cmbCOM.Items.Add(portNames[i]);
            }
        }
        private void DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            rtf1.BeginInvoke(new transfer(updatedata));

        }

        public delegate void transfer();
        public void updatedata()
        {
            terima = serial.ReadLine();
            //terima = serial.ReadExisting();
            rtf1.AppendText(terima);
            buffer = ambil.Left(terima, 2);
            label4.Text = buffer;

            //try
            {
                switch (buffer)
                {
                    case "[a":
                        m1 = ambil.Mid(terima, 3, terima.Length - 5);
                        txtM1.Text = "LGA1: " + m1;
                        break;
                    case "[b":
                        m2 = ambil.Mid(terima, 3, terima.Length - 5);
                        txtM2.Text = "LGA2: " + m2;
                        break;
                    case "[c":
                        m3 = ambil.Mid(terima, 3, terima.Length - 5);
                        txtM3.Text = "LGA3: " + m3;
                        break;
                    case "[d":
                        rly = ambil.Mid(terima, 3, terima.Length - 5);
                        lblRly.Text = rly;
                        break;

                    case "[e":
                        sensor1 = ambil.Mid(terima, 3, terima.Length - 5);
                        sens1.Text = sensor1 + " cm";
                        break;
                    case "[f":
                        sensor2 = ambil.Mid(terima, 3, terima.Length - 5);
                        sens2.Text = sensor2 + " cm";
                        break;
                    case "[t":
                        //lblTimer.Text = ambil.Right(terima, terima.Length - 1);
                        lblTimer.Text = ambil.Mid(terima, 3, terima.Length - 5);
                        break;
                    default:
                        break;
                }
            }
            //catch { }
            
        }

        private void btnKONEK_Click(object sender, EventArgs e)
        {
            try
            {

                serial.PortName = cmbCOM.Text;
                serial.BaudRate = Convert.ToInt32(txtBAUD.Text);
                serial.Parity = System.IO.Ports.Parity.None;
                serial.DataBits = 8;
                serial.StopBits = System.IO.Ports.StopBits.One;
                serial.DiscardNull = false;
                serial.Open();

            }
            catch { }
        }

        private void btnDISKONEK_Click(object sender, EventArgs e)
        {
            serial.Close();
        }

        private void cmdSend_Click(object sender, EventArgs e)
        {
            //serial.Write(txtKirim.Text + Environment.NewLine);
        }

        private void cmdKirimA_Click(object sender, EventArgs e)
        {
            serial.Write(txtlga1.Text + Environment.NewLine);
        }

        private void cmdKirimB_Click(object sender, EventArgs e)
        {
            serial.Write(txtlga2.Text + Environment.NewLine);
        }

        private void cmdKirimC_Click(object sender, EventArgs e)
        {
            serial.Write(txtlga3.Text + Environment.NewLine);
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            serial.Write("[e]" + Environment.NewLine);
        }

        private void lga1_Scroll(object sender, ScrollEventArgs e)
        {
            txtlga1.Text = "[a," + Convert.ToString(lga1.Value)+"]";
            
        }

        private void lga2_Scroll(object sender, ScrollEventArgs e)
        {
            txtlga2.Text = "[b," + Convert.ToString(lga2.Value*-1)+"]";
            
        }

        private void lga3_Scroll(object sender, ScrollEventArgs e)
        {
            txtlga3.Text = "[c," + Convert.ToString(lga3.Value)+"]";
            
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void cmdRLY_Click(object sender, EventArgs e)
        {
            
        }

        private void cmdRLYoff_Click(object sender, EventArgs e)
        {
           
        }

        private void cmdRLY_Click_1(object sender, EventArgs e)
        {
            serial.Write("[c,100]" + Environment.NewLine);
            delay();
            serial.Write("[d,0]" + Environment.NewLine);
            serial.Write("[c,0]" + Environment.NewLine);
        }

        private void cmdRLYoff_Click_1(object sender, EventArgs e)
        {
            serial.Write("[d,1]" + Environment.NewLine);
            serial.Write("[t]" + Environment.NewLine);
        }

        
        private void delay()
        {
            for (int d = 0; d < 50000; d++)
            { }
        }

        
        private void cmdLepas_Click_1(object sender, EventArgs e)
        {
            serial.Write("[g]" + Environment.NewLine);
        }

        private void btnAmbil_Click_1(object sender, EventArgs e)
        {
            /*
            serial.Write("[c,0]" + Environment.NewLine);
            //delay();
            serial.Write("[d,0]" + Environment.NewLine);
            //delay();
            serial.Write("[c,10000]" + Environment.NewLine);
            //delay();
            serial.Write("[d,1]" + Environment.NewLine);
            //delay();
            serial.Write("[c,0]" + Environment.NewLine);
            */
            
            serial.Write("[h]" + Environment.NewLine);
        }

        private void lblTimer_Click_1(object sender, EventArgs e)
        {
            serial.Write("[t]" + Environment.NewLine);
        }

    }
}
