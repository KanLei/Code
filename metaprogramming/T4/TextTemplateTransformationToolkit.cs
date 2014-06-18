/*
 * 模仿 T4(Text Template Transformation Toolkit) 模板文本生成工具 
 */

using System;
using System.Linq;

namespace TextTemplateTransformationToolkit
{
    class Program
    {
        static void Main(string[] args)
        {
            Type[] types_to_generate = new[]
            {
                typeof(bool),typeof(byte),
                typeof(char),typeof(decimal)
                // emit...
            };
            Console.WriteLine("using System;");
            Console.WriteLine("public static class greater");
            Console.WriteLine("{");
            foreach (var type in types_to_generate)
            {
                Console.WriteLine("public static {0} of({0} left, {0} right)", type.Name);
                Console.WriteLine("{");
                Type icomparable = (from intf in type.GetInterfaces()
                                    where typeof(IComparable<>).MakeGenericType(type).IsAssignableFrom(intf)
                                    ||
                                    typeof(IComparable).IsAssignableFrom(intf)
                                    select intf).FirstOrDefault();
                if (icomparable != null)
                {
                    Console.WriteLine("return left.CompareTo(right) < 0 ? right : left");
                }
                else
                {
                    throw new ApplicationException(string.Format("Type {0} must implement on of the IComparable or IComparable<{0}> interfaces.", type.Name));
                }
                Console.WriteLine("}");
            }
            Console.WriteLine("}");

            Console.Read();
        }
    }
}
