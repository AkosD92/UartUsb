using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibUART
{
    public static class Connection
    {
        public static string ToLine1;
        public static string ToLine2;

        public enum STATE_en {FAIL, PASS, UNEXPECTED};

        static SerialPort ComPort = new SerialPort();

        public static STATE_en InitSerialPort(string selectedPort)
        {
            ComPort.PortName = selectedPort;

            ComPort.BaudRate = 9600;
            ComPort.DataBits = 8;
            ComPort.StopBits = StopBits.One;
            ComPort.Parity = Parity.None;

            ComPort.ReadTimeout = 500;
            ComPort.WriteTimeout = 500;

          

            return STATE_en.PASS;

        }

        public static string[] GetComPorts()
        {
            return SerialPort.GetPortNames();
        }

        public static void WriteMessage()
        {
            ComPort.Open();
            ComPort.WriteLine(ToLine1);
            ComPort.WriteLine(ToLine2);
            ComPort.Close();
        }
    }
}
