/*
 * 使用 Console.Write() 动态生成类
 * 
 * There is no clear separation between the boilerplate(样板文件) text that needs to be
 * emitted and control code that runs over and around it.
 * This lack of separation reduces comprehension, slow down development,
 * and leads to otherwise avoidable errors.
 * Moreover, the real benefilts of metaprogramming have been lost.
 */

using System;
using System.Collections.Generic;
using System.Linq;

namespace GenerateCodeWithConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            string className = "DynamicCar";
            bool generateCtor = true;
            var properties = new List<Tuple<Type, string, bool>>()
            {
                Tuple.Create(typeof(string), "Make", true),
                Tuple.Create(typeof(string), "Model", true),
                Tuple.Create(typeof(int), "Year", true),
                Tuple.Create(typeof(int), "MPG", false)
            };

            GenerateDataClass(className, properties, generateCtor);

            Console.Read();
        }

        static void GenerateDataClass(string className, List<Tuple<Type, string, bool>> properties, bool generateCtor = true)
        {
            Console.WriteLine("public class {0}", className);
            Console.WriteLine("{");
            foreach (var property in properties)
            {
                Console.WriteLine("    public {0} {1} {{ get; {2}set;}}",
                    property.Item1, property.Item2, property.Item3 ? "" : "private ");
            }
            Console.Write(Environment.NewLine);
            if (generateCtor)
            {
                Console.WriteLine("    public {0}(", className);
                for (int ndx = 0; ndx < properties.Count; ndx++)
                {
                    Console.WriteLine("    {0}{1} {2}",
                        (ndx > 0) ? ", " : "",
                        properties[ndx].Item1,
                        properties[ndx].Item2,
                        properties[ndx].Item3);
                }
                Console.WriteLine("    )");
                Console.WriteLine("    {");
                foreach (var property in properties)
                {
                    Console.WriteLine("        this.{0} = {0};", property.Item2);
                }
                Console.WriteLine("    }");
                Console.WriteLine("}");
            }
        }
    }
}
