using System;
using System.Linq.Expressions;

namespace Lei.ExpressionDemo
{
    class ExpressionWithTryCatch
    {
        static void Main(string[] args)
        {
            var x = Expression.Parameter(typeof(int));
            var y = Expression.Parameter(typeof(int));

            var lambda = Expression.Lambda(
                Expression.TryCatch(
                  Expression.Block(
                    Expression.AddChecked(x, y)),
                Expression.Catch(
                    typeof(OverflowException),
                    Expression.Constant(0))), x, y);

            var func = lambda.Compile() as Func<int, int, int>;
            Console.WriteLine(func(2, 3));  // 5
            Console.WriteLine(func(int.MaxValue, int.MaxValue));  // 0

            Console.Read();
        }
    }
}
