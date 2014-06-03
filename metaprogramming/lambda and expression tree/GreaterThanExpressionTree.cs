using System;
using System.Linq.Expressions;


namespace GreaterThanExpressionTree
{
    class Program
    {
        static void Main(string[] args)
        {
            Expression<Func<int, int, bool>> greaterThanExpr = (left, right) => left > right;
            // bool result = greaterThanExpr(7, 11);  Compile Error!
            var greaterThan = greaterThanExpr.Compile();
            bool result = greaterThan(7, 11);

            int l = 7, r = 11;
            Console.WriteLine(CompileLambda()(l,r));

            Console.Read();
        }

        static Func<int, int, bool> CompileLambda()
        {
            ParameterExpression left = Expression.Parameter(typeof(int), "left");
            ParameterExpression right = Expression.Parameter(typeof(int), "right");

            Expression<Func<int, int, bool>> greaterThanExpr = Expression.Lambda<Func<int, int, bool>>
                (
                    Expression.GreaterThan(left, right),
                    left,
                    right
                );

            return greaterThanExpr.Compile();
        }
    }
}
