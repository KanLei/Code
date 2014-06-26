/*
    设计一个算法判别一个算数表达式的圆括号是否正确配对。

    思路：遇到左括号'('入栈，遇到右括号')'出栈，如果栈中元素不足或多于则不匹配，反之，则匹配。
    注：不可全部将左括号入栈后，然后全部出栈，因为无法避免情况：) (
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

SeqStack* InitSeqList();                 // 初始化顺序表
void PushElement(SeqStack *L, datatype x); // 将元素入栈
datatype PopElement(SeqStack *L);               // 将元素出栈
void PrintElements(SeqStack *L);         // 输出所有元素
int IsParenthesisMatch(const datatype arr[]);           // 括号是否匹配

int main()
{
    datatype ch;
    int i;
    datatype arr[MAXSIZE];

    printf("\nPlease input the string：");
    scanf("%s", arr);

    printf(IsParenthesisMatch(arr) ? "匹配\n" : "不匹配\n");

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
    int index;
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
    if(L->last >= 0)
        return L->A[L->last--];
    else
        return '@';
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


/* 判断括号是否匹配 */
int IsParenthesisMatch(const datatype arr[])
{
    int i;
    SeqStack *p = InitSeqList();

    for(i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == '(')
            PushElement(p, arr[i]);    // 将左括号入栈
        else if(arr[i] == ')' && PopElement(p) != '(')  // 将右括号出栈
            return 0;
    }

    /* 以下代码已被上移 */
    // 将元素出栈，并与字符串进行比较
    /*for(i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == ')')
            if(PopElement(p) != '(')  // 将右括号出栈
                return 0;
    }*/

    // 判读栈中是否还存在左括号
    return PopElement(p) == '(' ? 0 : 1;
}
