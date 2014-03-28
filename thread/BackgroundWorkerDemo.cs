/*
 * BackgroundWorker is a helper class in the System.ComponentModel namespace
 * for managing a worker thread. It can be considered a general-purpose implementation
 * of the EAP, and provides the following features:
 * 1. A cooperative cancellation model
 * 2. The ability to safely update WPF or Windows Forms controls when the worker completes
 * 3. Forwarding of exceptioins to the completion event
 * 4. A protocol for reporting progress
 * 5. An implementation of IComponent allowing it to be sited in Visual Studio's designer
 * 
 * BackgroundWorker uses the thread pool, which means you should never call
 * 'Abort' on a BackgroundWorker thread.
 * 
 * BackgroundWorker 不是密封的，因此你可以通过继承自 BackgroundWorker 实现自己的工作类。
 * from threading in c#
 */

using System;
using System.ComponentModel;
using System.Threading;

namespace BackgroundWorkerDemo
{
    class Program
    {
        static BackgroundWorker _bw;

        static void Main(string[] arg)
        {
            _bw = new BackgroundWorker
            {
                WorkerReportsProgress = true,      // 报告工作的进度
                WorkerSupportsCancellation = true  // 支持异步的取消工作
            };
            _bw.DoWork += bw_DoWork;
            _bw.ProgressChanged += bw_ProgressChanged;
            _bw.RunWorkerCompleted += bw_RunWorkerCompleted;

            _bw.RunWorkerAsync("Hello to worker");  // 开始执行

            Console.WriteLine("Press Enter in the next 5 seconds to cancel.");
            Console.ReadLine();

            if (_bw.IsBusy) _bw.CancelAsync();  // 设置 CancellationPending 为 true

            Console.ReadLine();
        }

        private static void bw_DoWork(object sender, DoWorkEventArgs e)
        {
            for (int i = 0; i < 101; i += 20)
            {
                if (_bw.CancellationPending)  // 同过 CancelAsync() 设置
                {
                    e.Cancel = true;
                    return;
                }
                _bw.ReportProgress(i);       // 通知工作进度
                Thread.Sleep(1000);  // Just for the demo.
            }
            e.Result = "Congratulation!";  // This gets passed to RunWorkerCompleted
        }

        static void bw_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled)
            {
                Console.WriteLine("You canceled!");
            }
            else if (e.Error != null)
            {
                Console.WriteLine("Worker exception: " + e.Error.ToString());
            }
            else
            {
                Console.WriteLine("Complete: " + e.Result);
            }
        }

        private static void bw_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            Console.WriteLine("Reached " + e.ProgressPercentage + "%");
        }
    }
}
