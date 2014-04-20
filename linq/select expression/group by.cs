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

        // 对 word 进行分组，所有值为 word 类型
        // 根据 word.Contains('*') 条件进行分组，所以键为 bool 类型
        IEnumerable<IGrouping<bool, string>> selection = from word in keyWords
                                                         group word by word.Contains('*');

        foreach (IGrouping<bool, string> wordGroup in selection)
        {
            Console.WriteLine(Environment.NewLine + "{0}:", wordGroup.Key ? "Contextual Keywords" : "Keywords");

            // wordGroup 表示值的集合，wordGroup.Key 表示键
            foreach (string keyword in wordGroup)
            {
                Console.Write(" " + (wordGroup.Key ? keyword.Replace("*", null) : keyword));
            }
        }

        Console.Read();
    }
}