/*
 * 重写 ToString() 方法有利于调试，但是为了避免每个类中都要重写 ToString() 的繁琐，
 * 使用反射+扩展方法的方式实现。
 * 
 * 这种实现方式会造成性能的损失，但由于代码中几乎没有使用 ToString() 方法的时候，因此可以忽略造成的性能损失。
 */

using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection;


namespace OverrideToStringForDebug
{
    class Program
    {
        static void Main(string[] args)
        {
            var my = new MyClass() { Name = "LeiKan", Age = 23 };
            Console.WriteLine(my);

            Console.Read();
        }
    }

    [Test]
    class MyClass
    {
        public string Name { get; set; }
        public int Age { get; set; }

        public override string ToString()
        {
            return this.ToStringReflection();
        }
    }


    /*
     * 扩展方式实现重写 ToString(), 方便调试显示更具有描述性的信息
     */
    static class ObjectExtensions
    {
        public static string ToStringReflection<T>(this T @this)
        {
            return string.Join(" || ",
                new List<string>(
                    from prop in @this.GetType().GetProperties(BindingFlags.Instance | BindingFlags.Public)
                    where prop.CanRead
                    select string.Format("{0}: {1}", prop.Name, prop.GetValue(@this, null))
                    ).ToArray()
                   );
        }
    }
}
