/* source: Microsoft
 * 
 String reorder 

 * Time Limit:10000ms 
 * Case Time Limit:1000ms 
 * Memory Limit:256MB 

 Description 

 * For this question, your program is required to process an input string containing
 * only ASCII characters between ‘0’ and ‘9’, or between ‘a’ and ‘z’ (including ‘0’, ‘9’, ‘a’, ‘z’). 

 * Your program should reorder and split all input string characters into multiple segments,
 * and output all segments as one concatenated string. The following requirements should also be met,
 * 1. Characters in each segment should be in strictly increasing order. For ordering, ‘9’ is larger than ‘0’,
 * ‘a’ is larger than ‘9’, and ‘z’ is larger than ‘a’ (basically following ASCII character order).
 * 
 * 2. Characters in the second segment must be the same as or a subset of the first segment;
 * and every following segment must be the same as or a subset of its previous segment. 

 * Your program should output string “<invalid input string>” when the input contains
 * any invalid characters (i.e., outside the '0'-'9' and 'a'-'z' range). 

 Input 

 * Input consists of multiple cases, one case per line. Each case is one string consisting of ASCII characters. 

 Output 

 * For each case, print exactly one line with the reordered string based on the criteria above. 

 样例输入
 * aabbccdd
 * 007799aabbccddeeff113355zz
 * 1234.89898
 * abcdefabcdefabcdefaaaaaaaaaaaaaabbbbbbbddddddee

 样例输出
 * abcdabcd
 * 013579abcdefz013579abcdefz
 * <invalid input string>
 * abcdefabcdefabcdefabdeabdeabdabdabdabdabaaaaaaa  
 */

using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Text;

class Exercise
{
    static void Main()
    {
        string strs = StringReorder("dbacacdb");
        Console.WriteLine(strs);

        strs = "007799aabbccddeeff113355zz";
        Console.WriteLine(StringReorder(strs));


        strs = "1234.89898";
        Console.WriteLine(StringReorder(strs));

        strs = "abcdefabcdefabcdefaaaaaaaaaaaaaabbbbbbbddddddee";
        Console.WriteLine(StringReorder(strs));

        Console.Read();
    }

    // version 1
    static string StringReorder(string strs)
    {
        if (Regex.IsMatch(strs, @"[^a-z0-9]"))
        {
            return "<Invalid Input String>";
        }

        // 排序、分组
        var query = strs.OrderBy(x => x).GroupBy(y => y).Select(z => new { value = z.Key, count = z.Count() });
        var dicts = new Dictionary<object, int>();

        foreach (var q in query)
        {
            dicts.Add(q.value, q.count);
        }

        var count = dicts.Max(x => x.Value);            // 最长序列元素的个数
        var temp = new Dictionary<object, int>(dicts);  // 创建临时字典用于修改
        var sb = new StringBuilder();

        for (int i = 0; i < count; i++)
        {
            foreach (var d in dicts)
            {
                if (temp[d.Key] > 0)
                {
                    temp[d.Key]--;
                    sb.Append(d.Key);
                }
            }
        }
        return sb.ToString();
    }

    // version 2
    static string StringReorder(string strs)
    {
        if (Regex.IsMatch(strs, @"[^a-z0-9]"))
        {
            return "<Invalid Input String>";
        }

        // 排序、分组、转化为字典
        var query = strs.OrderBy(x => x)
                        .GroupBy(y => y)
                        .ToDictionary(z => z.Key, z => z.Count());

        var count = query.Max(x => x.Value);            // 最长序列元素的个数
        var sb = new StringBuilder();

        for (int i = 0; i < count; i++)
        {
            foreach (var d in query.ToList())  // ToList() 返回副本
            {
                if (query[d.Key] > 0)
                {
                    query[d.Key]--;
                    sb.Append(d.Key);
                }
            }
        }
        return sb.ToString();
    }
}
