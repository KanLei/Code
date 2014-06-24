/*
    编写一个算法，利用折半查找算法在一个有序表中插入一个元素x，并保持表的有序性。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

int BinarySearchIndex(datatype arr[], int length, datatype x);  /* 折半查找元素应插入的适当位置 */

int main()
{
    int arr[8] = {1, 2, 4, 5, 6, 8, 9};
	int length = 7;
	int i;

	BinarySearchIndex(arr, length, 2);

	for(i = 0; i < 8; i++)
	{
		printf("%d ",arr[i]);
	}


    return 0;
}

int BinarySearchIndex(datatype arr[], int length, datatype x)
{
	int middle;
	int index;
	int low = 0, high = length - 1;  // 最大下标为元素个数减 1
	while(low <= high)
	{
		middle = (low + high) / 2;

		if(arr[middle] < x)
			low = middle + 1;
		else if(arr[middle] > x)
			high = middle - 1;
		else
		{
			/* 返回 middle + 1 避免多移动一位元素如:
			   1 2 3 4 5
			   插入 3
			   返回 4 所在的下标，将4之后的元素后移一位（包括4）
			 */
			index = middle + 1;  // 只能是 middle，不能使用 low 或者 high
			break;
		}
	}
	if(low > high)  index = low;

	//  移动数组并插入元素
	for(;length >= index; length--)
	{
		arr[length+1] = arr[length];
	}
	arr[index] = x;
}
