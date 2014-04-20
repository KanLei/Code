/*
 * 去除重复项
 */

using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        IEnumerable<string> enumerableMethodNames = (from method in typeof(Enumerable).GetMembers(
                                                        System.Reflection.BindingFlags.Static |
                                                        System.Reflection.BindingFlags.Public)
                                                     select method.Name).Distinct();

        foreach (string method in enumerableMethodNames)
        {
            Console.Write(" {0}", method);
        }


        Console.Read();
    }
}