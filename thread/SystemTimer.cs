/*
 * Multithreaded Timer
 * System.Timers simply wraps the System.Threading.Timer,
 * providing additional convenience while using the identical
 * underlying engine.
 * 
 * 1. A component implementation, allowing it to be sited in Visual Studio's designer
 * 2. An Interval property instead of a Change method
 * 3. An Elapsed event instead of a callback delegate
 * 4. An Enabled property to start and stop the timer(its default value being false)
 * 5. Start and Stop methods in case you're confused by Enabled
 * 6. An AutoReset flag for indicating a recurring event(default value is true)
 * 7. A SynchronizingObject property with Invoke and BeginInvoke methods for
 *    safely calling methods on WPF elements and Windows Forms controls
 */

using System;
using System.Timers;  // System 命名空间下的 Timer

namespace SystemTimer
{
    class Program
    {
        static void Main(string[] arg)
        {
            Timer tmr = new Timer();
            tmr.Interval = 1000;

            tmr.Elapsed += tmr_Elapsed;
            tmr.Start();

            Console.ReadLine();
            tmr.Stop();         // Stop the timer

            Console.ReadLine();
            tmr.Start();        // Restart the timer

            Console.ReadLine();
            tmr.Dispose();  // 停止计时器并释放相关资源
        }

        static void tmr_Elapsed(object sender, ElapsedEventArgs e)
        {
            Console.WriteLine("tick...");
        }
    }
}