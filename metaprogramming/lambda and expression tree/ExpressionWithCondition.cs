using System;
using System.Linq.Expressions;

namespace Lei.ExpressionDemo
{
    class ExpressionWithCondition
    {
        static void Main(string[] args)
        {
            var @switch = Expression.Parameter(typeof(bool));
            var conditional = Expression.Condition(@switch,
                Expression.Constant(1),
                Expression.Constant(0));

            var func = (Expression.Lambda(conditional, @switch)).Compile() as Func<bool, int>;
            Console.WriteLine(func(false));

            Console.Read();
        }
    }
}
