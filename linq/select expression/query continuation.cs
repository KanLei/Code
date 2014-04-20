/*
 * into 避免了利用第一个查询的结果来写第二个查询，它可以作为一个管道运算符使用
 * 将第一个查询的结果同第二个查询的结果合并到一起。
 */

using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        string[] keyWords = { "one", "two*", "three*", "four", "five*" };

        // group by 之后，不能直接使用 select 进行投影
        // 使用 into 在现有查询结果上运行附加的查询，这不是 group by 子句的特有功能
        // 而是所有查询表达式的一个功能
        var selection = from word in keyWords
                        group word by word.Contains('*')
                            into groups
                            select new
                            {
                                IsContextualKeyword = groups.Key,
                                Items = groups
                            };

        foreach (var wordGroup in selection)
        {
            Console.WriteLine(Environment.NewLine + "{0}:", wordGroup.IsContextualKeyword ? "Contextual Keywords" : "Keywords");

            // wordGroup 表示值的集合，wordGroup.Key 表示键
            foreach (var keyword in wordGroup.Items)
            {
                Console.Write(" " + keyword.Replace("*", null));
            }
        }

        Console.Read();
    }
}