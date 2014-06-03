/*
 * 字符串逆置
 */

using System;

namespace StringReverse
{
    class Program
    {
        static void Main(string[] args)
        {
            string strs = "hello";
            Console.WriteLine(strs.ReverseByPointers());

            Console.Read();
        }
    }

    static class StringExtension
    {
        // solution 1
        public static string Reverse(this string @this)
        {
            char[] chararcters = @this.ToCharArray();
            Array.Reverse(chararcters);
            return new string(chararcters);
        }

        // solution 2
        public unsafe static string ReverseByPointers(this string @this)
        {
            string output = string.Copy(@this);

            fixed (char* s = output)
            {
                char t;

                for (int i = 0, j = output.Length - 1; i < j; i++, j--)
                {
                    t = s[i];
                    s[i] = s[j];
                    s[j] = t;
                }
            }

            return output;
        }
    }
}
