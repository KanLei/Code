/*
  题目：
  写一个算法，从一个给定的顺序表A中删除值在x~y(x <= y)之间的所有元素，
  要求以较高的效率来实现。
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
void DeleteElementBetweenXandY(SeqList *L, datatype x, datatype y);  //  删除x~y之间的元素
void Delete2(SeqList *L, datatype x, datatype y);

int main()
{
    int x;
    SeqList *p = InitSeqList();


    printf("\nPlease input the element：");
    while(scanf("%d", &x))
    {
        InsertElement(p, x);    // 插入元素

        PrintElements(p);       //  再次输出所有元素

        printf("\nPlease input the element：");
    }

    //DeleteElementBetweenXandY(p, 2, 6);
    Delete2(p, 2, 6);
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

// 方法1
/* 删除x~y之间的元素 */
void DeleteElementBetweenXandY(SeqList *L, datatype x, datatype y)
{
    datatype *p , *q;
    int i, num = -1;

    p = q = L->A;
    for(i = 0; i <= L->last; i++, q++)
    {
        if(*q < x || *q > y)
        {
            *p++ = *q;
            num++;  // 记录元素的个数
        }
    }
    L->last = num;
}


// 方法2
/* 删除x~y之间的元素 */
void Delete2(SeqList *L, datatype x, datatype y)
{
    int i, n;

    for(i = n = 0; i <= L->last; i++)
    {
        if(L->A[i] >= x && L->A[i] <= y)
            n++;
        else
            L->A[i - n] = L->A[i];
    }
    L->last = i - n - 1;	// 总数 i 减去范围内的个数 n
}
