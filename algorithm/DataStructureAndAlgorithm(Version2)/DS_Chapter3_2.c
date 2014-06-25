/*
    �������� se[m] ���ѭ�����е�Ԫ�أ�ͬʱ����� rear �� front �ֱ���Ϊ��ͷ�Ͷ�βָ�룬
    �Ҷ�ͷָ��ָ���ͷ��ǰһ��λ�ã�д��������Ƶ�ѭ��������Ӻͳ��ӵ��㷨��
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


CSeQueue* InitSeQueue(); /* ��ʼ��ѭ������ */
int InQueue(CSeQueue *q, datatype x);      /* ��� */
int OutQueue(CSeQueue *q, datatype *x); /* ���� */
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

/* ��ʼ��ѭ������ */
CSeQueue* InitSeQueue()
{
    CSeQueue *q = malloc(sizeof(CSeQueue));
    assert(q != NULL);
    q->front = q->rear = -1;

    return q;
}

/* ��� */
int InQueue(CSeQueue *q, datatype x)
{
    q->rear = (q->rear + 1) % MAXSIZE;
    if(q->rear == q->front)
    {
        printf("����������");
        return 0;
    }
    else
    {
        q->data[q->rear] = x;
        return 1;
    }
}

/* ���� */
int OutQueue(CSeQueue *q, datatype *x)
{
    if(q->front == q->rear)
    {
        printf("����Ϊ�գ�");
        return 0;
    }
    else
    {
        *x = q->data[(++q->front) % MAXSIZE];
        return 1;
    }
}

/* �������Ԫ�� */
void PrintElement(CSeQueue *q)
{
    while(((q->front + 1) % MAXSIZE) != q->rear)
    {
        printf("%d ", q->data[(++q->front) % MAXSIZE]);
    }
    printf("%d ", q->data[(++q->front) % MAXSIZE]);
}
