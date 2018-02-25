using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using LibUART;

namespace UART
{
 
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            StatusText.Text = "N/A";
            StatusText.Foreground = Brushes.Orange;

            BtnSend.IsEnabled = false;

            string[] AvailableComports = Connection.GetComPorts();
            foreach (string s in AvailableComports)
            {
                Comports.Items.Add(s);
            }
        }

        private void BtnCheck_Click(object sender, RoutedEventArgs e)
        {
            string selectedPort = Convert.ToString(Comports.Text);
            Connection.STATE_en isInitSucceeded = Connection.InitSerialPort(selectedPort);

            if (isInitSucceeded == Connection.STATE_en.PASS)
            {
                StatusText.Text = "PASS";
                StatusText.Foreground = Brushes.Green;
                BtnSend.IsEnabled = true;
            }
            else if (isInitSucceeded == Connection.STATE_en.FAIL)
            {
                StatusText.Text = "FAIL";
                StatusText.Foreground = Brushes.Red;
            }

        }

        private void BtnSend_Click(object sender, RoutedEventArgs e)
        {
            string selectedPort = Convert.ToString(Comports.Text);

            Connection.ToLine1 = Line1.Text;
            Connection.ToLine2 = Line2.Text;

            Connection.InitSerialPort(selectedPort);
            Connection.WriteMessage();

        }
    }
}
