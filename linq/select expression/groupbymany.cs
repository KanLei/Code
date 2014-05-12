/*
  自定义扩展方法支持对多个关键字分组。
  先根据 Country 分组，再根据 City 分组：
  如：var result = customers.GroupByMany(c => c.Country, c => c.City);
 */

using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtesionGroupBy
{
    public class GroupResult
    {
        public object Key { get; set; }
        public int Count { get; set; }
        public IEnumerable Items { get; set; }
        public IEnumerable<GroupResult> SubGroups { get; set; }
        public override string ToString()
        {
            return string.Format("{0} {1}", Key, Count);
        }
    }

    public static class Extension
    {
        public static IEnumerable<GroupResult> GroupByMany<TElement>(
            this IEnumerable<TElement> elements,
            params Func<TElement, object>[] groupSelectors)
        {
            if (groupSelectors.Length > 0)
            {
                var selector = groupSelectors.First();

                // reduce the list recursively until zero
                var nextSelectors = groupSelectors.Skip(1).ToArray();
                return elements.GroupBy(selector).Select(
                    g => new GroupResult
                    {
                        Key = g.Key,
                        Count = g.Count(),
                        Items = g,
                        SubGroups = g.GroupByMany(nextSelectors)
                    });
            }
            else
                return null;
        }
    }
}
