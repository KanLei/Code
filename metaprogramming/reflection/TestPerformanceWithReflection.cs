using System;
using System.Diagnostics;


namespace TestPerformanceWithReflection
{
    class Program
    {
        static void Main(string[] args)
        {
            // 不使用反射
            var stopwatch = Stopwatch.StartNew();
            for (int i = 0; i < 5000; i++)
            {
                var random = new Random().Next();
            }
            stopwatch.Stop();
            Console.WriteLine(stopwatch.Elapsed.ToString());  // 00:00:00.0654749


            // 使用反射
            stopwatch.Restart();
            for (int i = 0; i < 5000; i++)
            {
                // 将这句代码移到 for 之外，可以提升性能
                var randomType = Type.GetType("System.Random");
                var nextMethod = randomType.GetMethod("Next", Type.EmptyTypes);
                var random = nextMethod.Invoke(Activator.CreateInstance(randomType), null);
            }
            stopwatch.Stop();
            Console.WriteLine(stopwatch.Elapsed.ToString());  // 00:00:00.2535609

            Console.Read();
        }
    }
}
