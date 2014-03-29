/*
 * In order for Wait to communicate with Pulse or PulseAll,
 * the synchronizing object (_locker, in our case) must be the same.
 * 
 * A race ensues between the main thread and the worker.
 * If Wait executes first, the signal works.
 * If Pulse executes first, the 'pulse is lost' and the worker remains forever stuck.
 * (This is differs form the behavior of an AutoResetEvent), so we use a boolean _go.
 */
using System;
using System.Threading;

namespace WaitAndPulse
{
    class Program
    {
        static readonly object _locker = new object();
        static bool _go;

        static void Main(string[] arg)
        {
            new Thread(Work).Start();

            Console.ReadLine();

            lock (_locker)
            {
                _go = true;
                Monitor.Pulse(_locker);
            }
        }

        static void Work()
        {
            lock (_locker)
            {
                while (!_go)
                {
                    /*
                     * 1. Release the lock on _locker
                     * 2. Blocks until _locker is "pulsed"
                     * 3. Reacquires the lock on _locker. If the lock is contended,
                     *    than it blocks until the block is available
                     */
                    Monitor.Wait(_locker);                  
                }
            }
            Console.WriteLine("Woken!!!");
        }
    }
}