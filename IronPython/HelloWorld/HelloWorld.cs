using System;

using IronPython.Hosting;
using Microsoft.Scripting.Hosting;

namespace PythonInteractCSharp
{
    class HelloWorld
    {
        static void Main(string[] args)
        {
            ScriptEngine engine = Python.CreateEngine();
            engine.Execute("print 'hello, world'");
            engine.ExecuteFile("HelloWorld.py");

            Console.Read();
        }
    }
}
