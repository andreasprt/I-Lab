namespace simulasi
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
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnCLEAR = new System.Windows.Forms.Button();
            this.btnDISKONEK = new System.Windows.Forms.Button();
            this.btnKONEK = new System.Windows.Forms.Button();
            this.cmbCOM = new System.Windows.Forms.ComboBox();
            this.txtBAUD = new System.Windows.Forms.TextBox();
            this.serial = new System.IO.Ports.SerialPort(this.components);
            this.rtf1 = new System.Windows.Forms.RichTextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtM3 = new System.Windows.Forms.TextBox();
            this.txtM2 = new System.Windows.Forms.TextBox();
            this.txtM1 = new System.Windows.Forms.TextBox();
            this.cmdKirimC = new System.Windows.Forms.Button();
            this.cmdKirimB = new System.Windows.Forms.Button();
            this.cmdKirimA = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txtlga3 = new System.Windows.Forms.TextBox();
            this.lga3 = new System.Windows.Forms.HScrollBar();
            this.txtlga2 = new System.Windows.Forms.TextBox();
            this.lga2 = new System.Windows.Forms.HScrollBar();
            this.lga1 = new System.Windows.Forms.HScrollBar();
            this.txtlga1 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.sens2 = new System.Windows.Forms.TextBox();
            this.sens1 = new System.Windows.Forms.TextBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.cmdRLYoff = new System.Windows.Forms.Button();
            this.cmdRLY = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.lblRly = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.cmdLepas = new System.Windows.Forms.Button();
            this.btnAmbil = new System.Windows.Forms.Button();
            this.lblTimer = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnCLEAR);
            this.groupBox1.Controls.Add(this.btnDISKONEK);
            this.groupBox1.Controls.Add(this.btnKONEK);
            this.groupBox1.Controls.Add(this.cmbCOM);
            this.groupBox1.Controls.Add(this.txtBAUD);
            this.groupBox1.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(2, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(116, 162);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Panel";
            // 
            // btnCLEAR
            // 
            this.btnCLEAR.Location = new System.Drawing.Point(8, 90);
            this.btnCLEAR.Name = "btnCLEAR";
            this.btnCLEAR.Size = new System.Drawing.Size(99, 35);
            this.btnCLEAR.TabIndex = 5;
            this.btnCLEAR.Text = "Hapus Data";
            this.btnCLEAR.UseVisualStyleBackColor = true;
            // 
            // btnDISKONEK
            // 
            this.btnDISKONEK.Location = new System.Drawing.Point(6, 127);
            this.btnDISKONEK.Name = "btnDISKONEK";
            this.btnDISKONEK.Size = new System.Drawing.Size(100, 28);
            this.btnDISKONEK.TabIndex = 3;
            this.btnDISKONEK.Text = "Putus Koneksi";
            this.btnDISKONEK.UseVisualStyleBackColor = true;
            this.btnDISKONEK.Click += new System.EventHandler(this.btnDISKONEK_Click);
            // 
            // btnKONEK
            // 
            this.btnKONEK.Location = new System.Drawing.Point(7, 59);
            this.btnKONEK.Name = "btnKONEK";
            this.btnKONEK.Size = new System.Drawing.Size(100, 25);
            this.btnKONEK.TabIndex = 2;
            this.btnKONEK.Text = "Connect";
            this.btnKONEK.UseVisualStyleBackColor = true;
            this.btnKONEK.Click += new System.EventHandler(this.btnKONEK_Click);
            // 
            // cmbCOM
            // 
            this.cmbCOM.FormattingEnabled = true;
            this.cmbCOM.Location = new System.Drawing.Point(6, 24);
            this.cmbCOM.Name = "cmbCOM";
            this.cmbCOM.Size = new System.Drawing.Size(99, 27);
            this.cmbCOM.TabIndex = 0;
            // 
            // txtBAUD
            // 
            this.txtBAUD.Location = new System.Drawing.Point(6, 25);
            this.txtBAUD.Name = "txtBAUD";
            this.txtBAUD.Size = new System.Drawing.Size(100, 26);
            this.txtBAUD.TabIndex = 1;
            this.txtBAUD.Text = "115200";
            this.txtBAUD.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // rtf1
            // 
            this.rtf1.Location = new System.Drawing.Point(647, 3);
            this.rtf1.Name = "rtf1";
            this.rtf1.Size = new System.Drawing.Size(158, 144);
            this.rtf1.TabIndex = 2;
            this.rtf1.Text = "";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtM3);
            this.groupBox2.Controls.Add(this.txtM2);
            this.groupBox2.Controls.Add(this.txtM1);
            this.groupBox2.Controls.Add(this.cmdKirimC);
            this.groupBox2.Controls.Add(this.cmdKirimB);
            this.groupBox2.Controls.Add(this.cmdKirimA);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.txtlga3);
            this.groupBox2.Controls.Add(this.lga3);
            this.groupBox2.Controls.Add(this.txtlga2);
            this.groupBox2.Controls.Add(this.lga2);
            this.groupBox2.Controls.Add(this.lga1);
            this.groupBox2.Controls.Add(this.txtlga1);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.Location = new System.Drawing.Point(124, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(502, 135);
            this.groupBox2.TabIndex = 7;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "LGA control";
            // 
            // txtM3
            // 
            this.txtM3.Location = new System.Drawing.Point(364, 101);
            this.txtM3.Name = "txtM3";
            this.txtM3.Size = new System.Drawing.Size(131, 20);
            this.txtM3.TabIndex = 21;
            // 
            // txtM2
            // 
            this.txtM2.Location = new System.Drawing.Point(364, 63);
            this.txtM2.Name = "txtM2";
            this.txtM2.Size = new System.Drawing.Size(131, 20);
            this.txtM2.TabIndex = 20;
            // 
            // txtM1
            // 
            this.txtM1.Location = new System.Drawing.Point(364, 28);
            this.txtM1.Name = "txtM1";
            this.txtM1.Size = new System.Drawing.Size(131, 20);
            this.txtM1.TabIndex = 19;
            // 
            // cmdKirimC
            // 
            this.cmdKirimC.Location = new System.Drawing.Point(282, 98);
            this.cmdKirimC.Name = "cmdKirimC";
            this.cmdKirimC.Size = new System.Drawing.Size(75, 23);
            this.cmdKirimC.TabIndex = 18;
            this.cmdKirimC.Text = "Kirim";
            this.cmdKirimC.UseVisualStyleBackColor = true;
            this.cmdKirimC.Click += new System.EventHandler(this.cmdKirimC_Click);
            // 
            // cmdKirimB
            // 
            this.cmdKirimB.Location = new System.Drawing.Point(282, 60);
            this.cmdKirimB.Name = "cmdKirimB";
            this.cmdKirimB.Size = new System.Drawing.Size(75, 23);
            this.cmdKirimB.TabIndex = 17;
            this.cmdKirimB.Text = "Kirim";
            this.cmdKirimB.UseVisualStyleBackColor = true;
            this.cmdKirimB.Click += new System.EventHandler(this.cmdKirimB_Click);
            // 
            // cmdKirimA
            // 
            this.cmdKirimA.Location = new System.Drawing.Point(282, 26);
            this.cmdKirimA.Name = "cmdKirimA";
            this.cmdKirimA.Size = new System.Drawing.Size(75, 23);
            this.cmdKirimA.TabIndex = 16;
            this.cmdKirimA.Text = "Kirim";
            this.cmdKirimA.UseVisualStyleBackColor = true;
            this.cmdKirimA.Click += new System.EventHandler(this.cmdKirimA_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 103);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 13);
            this.label3.TabIndex = 15;
            this.label3.Text = "LGA back";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(21, 66);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 14;
            this.label2.Text = "LGA2";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 13;
            this.label1.Text = "LGA1";
            // 
            // txtlga3
            // 
            this.txtlga3.Location = new System.Drawing.Point(209, 102);
            this.txtlga3.Name = "txtlga3";
            this.txtlga3.Size = new System.Drawing.Size(66, 20);
            this.txtlga3.TabIndex = 12;
            this.txtlga3.Text = "c1000";
            this.txtlga3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lga3
            // 
            this.lga3.Location = new System.Drawing.Point(76, 90);
            this.lga3.Maximum = 5000;
            this.lga3.Minimum = -5000;
            this.lga3.Name = "lga3";
            this.lga3.Size = new System.Drawing.Size(130, 32);
            this.lga3.TabIndex = 11;
            this.lga3.Scroll += new System.Windows.Forms.ScrollEventHandler(this.lga3_Scroll);
            // 
            // txtlga2
            // 
            this.txtlga2.Location = new System.Drawing.Point(209, 64);
            this.txtlga2.Name = "txtlga2";
            this.txtlga2.Size = new System.Drawing.Size(66, 20);
            this.txtlga2.TabIndex = 10;
            this.txtlga2.Text = "b1000";
            this.txtlga2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lga2
            // 
            this.lga2.Location = new System.Drawing.Point(76, 54);
            this.lga2.Maximum = 5000;
            this.lga2.Minimum = -5000;
            this.lga2.Name = "lga2";
            this.lga2.Size = new System.Drawing.Size(130, 30);
            this.lga2.TabIndex = 9;
            this.lga2.Scroll += new System.Windows.Forms.ScrollEventHandler(this.lga2_Scroll);
            // 
            // lga1
            // 
            this.lga1.Location = new System.Drawing.Point(76, 18);
            this.lga1.Maximum = 5000;
            this.lga1.Minimum = -5000;
            this.lga1.Name = "lga1";
            this.lga1.Size = new System.Drawing.Size(130, 30);
            this.lga1.TabIndex = 8;
            this.lga1.Scroll += new System.Windows.Forms.ScrollEventHandler(this.lga1_Scroll);
            // 
            // txtlga1
            // 
            this.txtlga1.Location = new System.Drawing.Point(209, 28);
            this.txtlga1.Name = "txtlga1";
            this.txtlga1.Size = new System.Drawing.Size(67, 20);
            this.txtlga1.TabIndex = 7;
            this.txtlga1.Text = "a1000";
            this.txtlga1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(330, 6);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(32, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "Code";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.sens2);
            this.groupBox3.Controls.Add(this.sens1);
            this.groupBox3.Controls.Add(this.pictureBox1);
            this.groupBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox3.Location = new System.Drawing.Point(2, 171);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(218, 98);
            this.groupBox3.TabIndex = 9;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Panel Sensor";
            // 
            // sens2
            // 
            this.sens2.Location = new System.Drawing.Point(7, 69);
            this.sens2.Name = "sens2";
            this.sens2.Size = new System.Drawing.Size(100, 20);
            this.sens2.TabIndex = 11;
            // 
            // sens1
            // 
            this.sens1.Location = new System.Drawing.Point(6, 17);
            this.sens1.Name = "sens1";
            this.sens1.Size = new System.Drawing.Size(100, 20);
            this.sens1.TabIndex = 10;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::simulasi.Properties.Resources.xxxx;
            this.pictureBox1.Location = new System.Drawing.Point(124, 17);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(82, 72);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 9;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // cmdRLYoff
            // 
            this.cmdRLYoff.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cmdRLYoff.Location = new System.Drawing.Point(207, 153);
            this.cmdRLYoff.Name = "cmdRLYoff";
            this.cmdRLYoff.Size = new System.Drawing.Size(75, 23);
            this.cmdRLYoff.TabIndex = 18;
            this.cmdRLYoff.Text = "Tutup";
            this.cmdRLYoff.UseVisualStyleBackColor = true;
            this.cmdRLYoff.Click += new System.EventHandler(this.cmdRLYoff_Click_1);
            // 
            // cmdRLY
            // 
            this.cmdRLY.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cmdRLY.Location = new System.Drawing.Point(126, 153);
            this.cmdRLY.Name = "cmdRLY";
            this.cmdRLY.Size = new System.Drawing.Size(75, 23);
            this.cmdRLY.TabIndex = 17;
            this.cmdRLY.Text = "Buka";
            this.cmdRLY.UseVisualStyleBackColor = true;
            this.cmdRLY.Click += new System.EventHandler(this.cmdRLY_Click_1);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(226, 184);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(106, 30);
            this.label6.TabIndex = 19;
            this.label6.Text = "Solenoid:";
            // 
            // lblRly
            // 
            this.lblRly.AutoSize = true;
            this.lblRly.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblRly.Location = new System.Drawing.Point(222, 223);
            this.lblRly.Name = "lblRly";
            this.lblRly.Size = new System.Drawing.Size(108, 37);
            this.lblRly.TabIndex = 20;
            this.lblRly.Text = "label7";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.label5);
            this.groupBox4.Controls.Add(this.lblTimer);
            this.groupBox4.Controls.Add(this.cmdLepas);
            this.groupBox4.Controls.Add(this.btnAmbil);
            this.groupBox4.Font = new System.Drawing.Font("Comic Sans MS", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox4.Location = new System.Drawing.Point(336, 153);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(457, 115);
            this.groupBox4.TabIndex = 23;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Control";
            // 
            // cmdLepas
            // 
            this.cmdLepas.Location = new System.Drawing.Point(79, 26);
            this.cmdLepas.Name = "cmdLepas";
            this.cmdLepas.Size = new System.Drawing.Size(75, 23);
            this.cmdLepas.TabIndex = 24;
            this.cmdLepas.Text = "Lepas";
            this.cmdLepas.UseVisualStyleBackColor = true;
            this.cmdLepas.Click += new System.EventHandler(this.cmdLepas_Click_1);
            // 
            // btnAmbil
            // 
            this.btnAmbil.Location = new System.Drawing.Point(257, 26);
            this.btnAmbil.Name = "btnAmbil";
            this.btnAmbil.Size = new System.Drawing.Size(85, 23);
            this.btnAmbil.TabIndex = 23;
            this.btnAmbil.Text = "Ambil";
            this.btnAmbil.UseVisualStyleBackColor = true;
            this.btnAmbil.Click += new System.EventHandler(this.btnAmbil_Click_1);
            // 
            // lblTimer
            // 
            this.lblTimer.AutoSize = true;
            this.lblTimer.Font = new System.Drawing.Font("Comic Sans MS", 24F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTimer.Location = new System.Drawing.Point(29, 52);
            this.lblTimer.Name = "lblTimer";
            this.lblTimer.Size = new System.Drawing.Size(109, 45);
            this.lblTimer.TabIndex = 25;
            this.lblTimer.Text = "Timer";
            this.lblTimer.Click += new System.EventHandler(this.lblTimer_Click_1);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(144, 64);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(292, 24);
            this.label5.TabIndex = 26;
            this.label5.Text = "<==== Click disini untuk waktu";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.ClientSize = new System.Drawing.Size(817, 264);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.lblRly);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.cmdRLYoff);
            this.Controls.Add(this.cmdRLY);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.rtf1);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Uji Coba";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnCLEAR;
        private System.Windows.Forms.Button btnDISKONEK;
        private System.Windows.Forms.Button btnKONEK;
        private System.Windows.Forms.ComboBox cmbCOM;
        private System.Windows.Forms.TextBox txtBAUD;
        private System.IO.Ports.SerialPort serial;
        private System.Windows.Forms.RichTextBox rtf1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button cmdKirimA;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtlga3;
        private System.Windows.Forms.HScrollBar lga3;
        private System.Windows.Forms.TextBox txtlga2;
        private System.Windows.Forms.HScrollBar lga2;
        private System.Windows.Forms.HScrollBar lga1;
        private System.Windows.Forms.TextBox txtlga1;
        private System.Windows.Forms.Button cmdKirimC;
        private System.Windows.Forms.Button cmdKirimB;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox sens2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TextBox sens1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button cmdRLYoff;
        private System.Windows.Forms.Button cmdRLY;
        private System.Windows.Forms.TextBox txtM3;
        private System.Windows.Forms.TextBox txtM2;
        private System.Windows.Forms.TextBox txtM1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lblRly;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label lblTimer;
        private System.Windows.Forms.Button cmdLepas;
        private System.Windows.Forms.Button btnAmbil;
    }
}

