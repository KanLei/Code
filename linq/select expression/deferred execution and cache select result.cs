/*
 * 延迟查询和缓存查询结果，避免重复查询造成性能损失
 */

using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        string[] keyWords = { "one", "two*", "three*", "four", "five*" };


        int delegateInvocations = 0;
        Func<string, string> func = text =>
        {
            delegateInvocations++;
            return text;
        };

        IEnumerable<string> selection = from keyword in keyWords
                                        where keyword.Contains('*')
                                        select func(keyword);

        Console.WriteLine("1. delegateInvocation={0}", delegateInvocations);

        // Executing count should invoke func once for each item selected.
        Console.WriteLine("2. Contextual keyword count={0}", selection.Count());

        Console.WriteLine("3. delegateInvocations={0}", delegateInvocations);

        // Executing count should invoke func once for each item selected.
        Console.WriteLine("4. Contextual keyword count={0}", selection.Count());

        Console.WriteLine("5. delegateInvocations={0}", delegateInvocations);

        // Cache the value so future counts will not trigger another invocation of the query
        List<string> selectionCache = selection.ToList();

        Console.WriteLine("6. delegateInvocations={0}", delegateInvocations);

        // Retrieve the count from the cached collection.
        Console.WriteLine("7. selectionCache count={0}", selectionCache.Count());

        Console.WriteLine("8. delegateInvocations={0}", delegateInvocations);

        /*
         * 1. delegateInvocation=0
         * 2. Contextual keyword count=3
         * 3. delegateInvocations=3
         * 4. Contextual keyword count=3
         * 5. delegateInvocations=6
         * 6. delegateInvocations=9
         * 7. selectionCache count=3
         * 8. delegateInvocations=9
         */

        Console.Read();
    }
}