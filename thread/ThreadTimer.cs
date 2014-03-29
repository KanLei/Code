/*
 * Multithreaded Timer
 * System.Threading.Timer is the simplest multithreaded timer:
 * it has just a constructor and two methods.
 */

using System;
using System.Threading;  // Threading 命名空间下的 Timer

namespace ThreadTimer
{
    class Program
    {
        static void Main(string[] arg)
        {
            // 延迟 5 秒执行，之后每隔 1 秒执行一次
            Timer tmr = new Timer(Tick, "tick...", 5000, 1000);

            Console.WriteLine(Thread.CurrentThread.ManagedThreadId);

            Console.ReadLine();
            tmr.Dispose();  // 停止计时器并释放相关资源
        }

        private static void Tick(object state)
        {
            // 线程池线程
            Console.WriteLine(Thread.CurrentThread.ManagedThreadId);
            Console.WriteLine(state);
        }
    }
}
