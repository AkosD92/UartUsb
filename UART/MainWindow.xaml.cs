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

namespace UART
{
 
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            StatusText.Text = "N/A";
            StatusText.Foreground = Brushes.Orange;

            SendStat.Text = "Not Sent";
            SendStat.Foreground = Brushes.Orange;

            BtnSend.IsEnabled = false;
        }
    }
}
