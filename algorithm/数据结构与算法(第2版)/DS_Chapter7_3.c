/*
    ��дһ���㷨�������۰�����㷨��һ��������в���һ��Ԫ��x�������ֱ�������ԡ�
*/

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

int BinarySearchIndex(datatype arr[], int length, datatype x);  /* �۰����Ԫ��Ӧ������ʵ�λ�� */

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
	int low = 0, high = length - 1;  // ����±�ΪԪ�ظ����� 1
	while(low <= high)
	{
		middle = (low + high) / 2;

		if(arr[middle] < x)
			low = middle + 1;
		else if(arr[middle] > x)
			high = middle - 1;
		else
		{
			/* ���� middle + 1 ������ƶ�һλԪ����:
			   1 2 3 4 5
			   ���� 3
			   ���� 4 ���ڵ��±꣬��4֮���Ԫ�غ���һλ������4��
			 */
			index = middle + 1;  // ֻ���� middle������ʹ�� low ���� high
			break;
		}
	}
	if(low > high)  index = low;

	//  �ƶ����鲢����Ԫ��
	for(;length >= index; length--)
	{
		arr[length+1] = arr[length];
	}
	arr[index] = x;
}
