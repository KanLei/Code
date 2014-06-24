/*
  题目：
  已知一顺序表A，其元素值非递减有序排列，
  编写一个算法删除顺序表中重复的元素。
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100   //  定义数组的最大长度
typedef int datatype; //  定义数据类型


/* 定义结构体用于存放数组和当前数组中元素的个数 */
typedef struct
{
    datatype A[MAXSIZE];
    int last;
} SeqList;

SeqList* InitSeqList();                 // 初始化顺序表
void InsertElement(SeqList *L, int x);  // 插入元素
void PrintElements(SeqList *L);         // 输出所有元素
SeqList* DeleteRepeatedElement(SeqList *L);  // 删除重复的元素
void Delete2(SeqList *L);
void Delete3(SeqList *L);
void Delete4(SeqList* L);

int main()
{
    int x;
    SeqList *p = InitSeqList();


    printf("\nPlease input the x：");
    while(scanf("%d", &x))
    {
        InsertElement(p, x);    // 插入元素

        PrintElements(p);       //  再次输出所有元素

        printf("\nPlease input the x：");
    }

    //PrintElements(DeleteRepeatedElement(p));  // 删除重复元素并输出
    Delete4(p);
    PrintElements(p);

    return 0;
}

/* 初始化顺序表 */
SeqList* InitSeqList()
{
    SeqList *p = malloc(sizeof(SeqList));   //  为 SeqList 分配内存空间
    assert(p != NULL);                      //  判断是否成功申请到内存空间
    p->last = -1;                           //  将 last 值初始化为 -1
    return p;
}


/* 插入元素 */
void InsertElement(SeqList *L, datatype x)
{
    int index;
    if(L->last == MAXSIZE - 1)
    {
        printf("数组元素已满！");
    }
    else
    {
        index = L->last;

        /*从后往前遍历数组，只要数组元素值大于要插入的元素值，就把该元素往后移动一位*/
        while(index > -1 && L->A[index] > x)
        {
            L->A[index + 1] = L->A[index];
            index--;
        }
        L->A[++index] = x;  // 将 x 插入
        L->last++;          // 修改 last 的值
    }
}


/*  输出所有元素 */
void PrintElements(SeqList *L)
{
    int i;
    for(i = 0; i <= L->last; i++)
    {
        printf("%d  ", L->A[i]);
    }
    printf("\n");
}

// 方法1:利用另一个线性表来存储
/* 删除多余的值 */
SeqList* DeleteRepeatedElement(SeqList *L)
{
    int i;
    SeqList *seq = InitSeqList();
    seq->A[++seq->last] = L->A[0];  // 取第一个元素的值存放到seq中

    for(i = 1; i <= L->last; i++)
    {
        if(L->A[i] != seq->A[seq->last])
        {
            seq->A[++seq->last] = L->A[i];
        }
    }
    free(L->A);
    return seq;
}


// 方法2
/* 删除多余的值 */
void Delete2(SeqList *L)
{
    int i, j, k, n;
    for(i = 0; i < L->last; i++)
    {
        k = i + 1;
        while(k <= L->last && L->A[i] == L->A[k])
        {
            k++;
        }

        n = k - i - 1;  // 计算重复元素的个数
        for(j = k; j <= L->last; j++)
            L->A[j - n] = L->A[j];

        L->last = L->last - n;
    }
}

// 方法3
void Delete3(SeqList *L)
{
    int i, j;
    for(i = 0, j = 1; j <= L->last; j++)
    {
        if(L->A[i] != L->A[j])
            L->A[++i] = L->A[j];
    }
    L->last = i;
}

void Delete4(SeqList* L)
{
	//int k = 0;
	int i, j;
	for(i=0;i< L->last;i++)
	{
		if(L->A[i] == L->A[i+1])
		{
			//k++;
			for(j=i; j< L->last; j++)
			{
				L->A[j] = L->A[j+1];
			}
			i--;
			L->last--;
		}
	}
	//L->last = L->last - k;
}
