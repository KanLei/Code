/*
    称正读和反读都相同的字符序列为"回文"，例如，"abcddcba"、"qwerewq" 是回文，
    "ashgash" 不是回文。试写一个算法判断读入的一个以 '@' 为结束符的字符序列是否为回文。
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100   //  定义数组的最大长度
typedef char datatype; //  定义数据类型


/* 定义结构体用于存放数组和当前数组中元素的个数 */
typedef struct
{
    datatype A[MAXSIZE];
    int last;
} SeqStack;

SeqStack* InitSeqList();                // 初始化顺序表
void PushElement(SeqStack *L, datatype x); // 将元素入栈
datatype PopElement(SeqStack *L);               // 将元素出栈
void PrintElements(SeqStack *L);         // 输出所有元素
int IsPalindrome(const datatype arr[]);           // 是否是回文

int main()
{
    datatype arr[MAXSIZE];

    printf("\nPlease input the string：");
    scanf("%s", arr);

    printf(IsPalindromeUsePoint(arr) ? "是回文\n" : "不是回文\n");

    return 0;
}

/* 初始化顺序表 */
SeqStack* InitSeqList()
{
    SeqStack *p = malloc(sizeof(SeqStack));   //  为 SeqList 分配内存空间
    assert(p != NULL);                      //  判断是否成功申请到内存空间
    p->last = -1;                           //  将 last 值初始化为 -1
    return p;
}


/* 将元素入栈 */
void PushElement(SeqStack *L, datatype x)
{
    if(L->last == MAXSIZE - 1)
    {
        printf("数组元素已满！");
    }
    else
    {
        L->A[++L->last] = x;  // 将 x 插入
    }
}


/* 将元素出栈 */
datatype PopElement(SeqStack *L)
{
    assert(L->last != -1);  // 栈已空
    return L->A[L->last--];
}

/*  输出所有元素 */
void PrintElements(SeqStack *L)
{
    int i;
    for(i = 0; i <= L->last; i++)
    {
        printf("%c", L->A[i]);
    }
    printf("\n");
}


/* 判断是否是回文，借用栈 */
int IsPalindrome(const datatype arr[])
{
    int i;
    SeqStack *p = InitSeqList();

    for(i = 0; arr[i] != '@'; i++)
    {
        PushElement(p, arr[i]);    // 将元素入栈
    }

    // 将元素出栈，并与字符串进行比较
    for(i = 0; arr[i] != '@'; i++)
    {
        if(PopElement(p) != arr[i])
            return 0;  // 不是回文
    }
    return 1;  // 是回文
}

/* 判断是否是回文，借用指针 */
int IsPalindromeUsePoint(const char* str)
{
    const char* start = str;
    const char* end = str;
    while(*end != '@')  end++;
    for(--end; (start < end) && (*start == *end); --end, ++start)
        ;
    return start < end ? 0 : 1;
}
