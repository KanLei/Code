/*
 * 1 MSDN library, “Best Practices for Assembly Loading,” http://mng.bz/kv4g.
 * 2 Eric Lippert (blog), “In Foof We Trust: A Dialogue,” http://mng.bz/k0eQ.
 * 3 Patrick Smacchia (posted by), “Elegant infoof operators in C# (read Info Of),” June 28, 2010, http://mng.bz/YK8h
 */

using System;
using System.Reflection;


namespace GetTypeAndAssemblyWithReflection
{
    class Program
    {
        static void TypeWithReflection()
        {
            // 基于字符串的方式更加灵活，但易出错
            var type = Type.GetType("System.Random");   // 默认不抛出异常
            type = Type.GetType("System.Random", true);  // 如果未找到，则抛出异常
            type = Type.GetType("system.random", true, true);   // 忽略大小写

            // 基于类型或实例的方式则更加安全
            type = typeof(Random);
            type = (new Random()).GetType();

            var lazyType = typeof(Lazy<>);  // generic type
            var tuple = typeof(Tuple<,,>);  // generic type with three parameters
        }


        // 通过反射动态加载程序集实现扩展，而不用重新编译之前的整个项目
        static void AssemblyWithReflection()
        {
            // if the assembly is already loaded into the current AppDomain, it'll return the existing reference.

            var assembly = Assembly.Load(new AssemblyName() { Name = "mscorlib", Version = new Version(4, 0, 0, 0) });
            var assembly2 = Assembly.Load("mscorlib, Version=4.0.0.0");
            var assembly3 = Assembly.LoadFrom(@"file:///C:/Windows/Microsoft.NET/Framework/v4.0.30319/mscorlib.dll");
        }

        static void ExecutingCode()
        {
            var lazyIntType = typeof(Lazy<int>);
            var lazyInt = Activator.CreateInstance(lazyIntType) as Lazy<int>;

            // 已经知道要创建的指定实例类型
            var lazyInt2 = Activator.CreateInstance<Lazy<int>>();
        }
    }
}
