using System;
using System.Threading.Tasks;

namespace Lambda_with_Asynchronous_and_Synchronous
{
    class Program
    {
        static void Main(string[] args)
        {
            Action action1 = () => { };
            Func<Task> func1 = async () => { await Task.Yield(); };

            Func<int> func2 = () => { return 13; };
            Func<Task<int>> func3 = async () => { await Task.Yield(); return 13; };

            Action<int> action2 = x => { };
            Func<int, Task> func4 = async x => { await Task.Yield(); };

            Func<int, int> func5 = x => { return 13; };
            Func<int, Task<int>> func6 = async x => { await Task.Yield(); return 13; };

            Action<int, int> action3 = (x, y) => { };
            Func<int, int, Task> func7 = async (x, y) => { await Task.Yield(); };

            Func<int, int, int> func8 = (x, y) => { return 13; };
            Func<int, int, Task<int>> func9 = async (x, y) => { await Task.Yield(); return 13; };
        }
    }
}
