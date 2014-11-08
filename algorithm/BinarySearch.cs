
class Search
{
    /// <summary>
    /// 折半查找
    /// </summary>
    /// <param name="key">要查找的 key</param>
    /// <param name="array">有序数组</param>
    /// <returns>查找成功返回下标位置，否则返回 null</returns>
    static int? BinarySearch(char key, char[] array)
    {
        int low = 0;
        int high = array.Length - 1;

        while (low <= high)
        {
            int middle = (low + high) / 2;
            int value = array[middle];

            if (value < key)
            {
                low = middle + 1;
            }
            else if (value > key)
            {
                high = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return null;
    }
}

