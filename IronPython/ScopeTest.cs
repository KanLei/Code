/*
 * 注意 python 代码作为 c# 字符串字面量嵌入时的空格缩进
 */

using System;

using IronPython.Hosting;
using Microsoft.Scripting.Hosting;

namespace ScopeWithVariableAndMethod
{
    class ScopeTest
    {
        static void Main(string[] args)
        {
            ScopeWithFunction();

            Console.Read();
        }

        /// <summary>
        /// Scope 与变量交互
        /// </summary>
        static void ScopeWithVariable()
        {
            string python = @"text = 'hello'
output = input + 1
";
            Console.WriteLine(python);

            ScriptEngine engine = Python.CreateEngine();
            ScriptScope scope = engine.CreateScope();
            scope.SetVariable("input", 10);
            engine.Execute(python, scope);  // 与作用域进行交互

            Console.WriteLine(scope.GetVariable<string>("text"));
            Console.WriteLine(scope.GetVariable<int>("input"));
            Console.WriteLine(scope.GetVariable<int>("output"));
        }


        /// <summary>
        /// Scope 与函数交互
        /// </summary>
        static void ScopeWithFunction()
        {
            string python = @"
def sayHello(user):
    print 'Hello %(name)s' % {'name' : user}
";

            ScriptEngine engine = Python.CreateEngine();
            ScriptScope scope = engine.CreateScope();
            engine.Execute(python, scope);
            dynamic function = scope.GetVariable("sayHello");
            function("Lei");
        }
    }
}
