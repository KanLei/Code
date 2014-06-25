/*
    设以数组 se[m] 存放循环队列的元素，同时设变量 rear 和 front 分别作为队头和队尾指针，
    且队头指针指向队头的前一个位置，写出这样设计的循环队列入队和出队的算法。
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 10
typedef int datatype;

typedef struct
{
    datatype data[MAXSIZE];
    int front, rear;
} CSeQueue;


CSeQueue* InitSeQueue(); /* 初始化循环队列 */
int InQueue(CSeQueue *q, datatype x);      /* 入队 */
int OutQueue(CSeQueue *q, datatype *x); /* 出队 */
void PrintElement(CSeQueue *q);

int main()
{
    datatype num;
    CSeQueue *q = InitSeQueue();

    do
    {
        printf("Please input a number:");
        if((scanf("%d", &num)) != 1)
            break;
        else
        {
            InQueue(q, num);
        }
    }
    while(1);
    //PrintElement(q);
    OutQueue(q, &num);
    printf("%d ", num);
    OutQueue(q, &num);
    printf("%d ", num);
    OutQueue(q, &num);
    printf("%d ", num);
    return 0;
}

/* 初始化循环队列 */
CSeQueue* InitSeQueue()
{
    CSeQueue *q = malloc(sizeof(CSeQueue));
    assert(q != NULL);
    q->front = q->rear = -1;

    return q;
}

/* 入队 */
int InQueue(CSeQueue *q, datatype x)
{
    q->rear = (q->rear + 1) % MAXSIZE;
    if(q->rear == q->front)
    {
        printf("队列已满！");
        return 0;
    }
    else
    {
        q->data[q->rear] = x;
        return 1;
    }
}

/* 出队 */
int OutQueue(CSeQueue *q, datatype *x)
{
    if(q->front == q->rear)
    {
        printf("队列为空！");
        return 0;
    }
    else
    {
        *x = q->data[(++q->front) % MAXSIZE];
        return 1;
    }
}

/* 输出队列元素 */
void PrintElement(CSeQueue *q)
{
    while(((q->front + 1) % MAXSIZE) != q->rear)
    {
        printf("%d ", q->data[(++q->front) % MAXSIZE]);
    }
    printf("%d ", q->data[(++q->front) % MAXSIZE]);
}
