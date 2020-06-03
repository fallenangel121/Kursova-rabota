using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace EditorApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        [DllImport("EDITORSOURCE.dll", CallingConvention = CallingConvention.Cdecl)]

        static extern int executable_function([MarshalAs(UnmanagedType.LPStr)] String Input);

        int Checker = 1;
        private void button1_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(Input.Text))
            {
                System.Windows.Forms.MessageBox.Show("Add some text!");
                System.Windows.Forms.Application.Exit();
            }

            Checker = executable_function(Input.Text);

            if (Checker == 0)
            {
                System.Windows.Forms.MessageBox.Show("Done, check the output file!");
                System.Windows.Forms.Application.Exit();
            }
            else
            {
                System.Windows.Forms.MessageBox.Show("Error!");
                System.Windows.Forms.Application.Exit();
            }
        }
    }
}
