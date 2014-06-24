/*
    ������ջ��һ�����������á�
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100   //  �����������󳤶�
typedef char datatype; //  ������������


/* ����ṹ�����ڴ������͵�ǰ������Ԫ�صĸ��� */
typedef struct
{
    datatype A[MAXSIZE];
    int last;
} SeqList;

/* ��������ڵ�ṹ */
typedef struct node
{
    datatype data;
    struct node* next;
} Node, *LinkList;

LinkList InitLinkList();                 // ��ʼ������
SeqList* InitSeqList();
void PushElement(SeqList *Q, LinkList L); // ��Ԫ����ջ
datatype PopElement(SeqList *Q);               // ��Ԫ�س�ջ
void PrintElements(LinkList L);         // �������Ԫ��
int ReverseLinkList(SeqList *Q);


int main()
{
    datatype arr[MAXSIZE];
    SeqList *Q = InitSeqList();
    char ch;
    Node *node;
    LinkList rear;

    // ����ͷ���
    LinkList p = InitLinkList();
    rear = p;
    // ����������
    printf("\nPlease input the string��");
    while((ch = getchar()) != '@')
    {
        node = malloc(sizeof(Node));
        node->data = ch;
        node->next = NULL;
        rear->next = node;
        rear = rear->next;
    }

    PushElement(Q , p);
    ReverseLinkList(Q);

    return 0;
}

/* ��ʼ������ */
LinkList InitLinkList()
{
    LinkList p = malloc(sizeof(LinkList));   //  Ϊ SeqList �����ڴ�ռ�
    assert(p != NULL);                      //  �ж��Ƿ�ɹ����뵽�ڴ�ռ�
    p->next = NULL;                           //  �� last ֵ��ʼ��Ϊ -1
    return p;
}

SeqList* InitSeqList()
{
    SeqList *q = malloc(sizeof(SeqList));   //  Ϊ SeqList �����ڴ�ռ�
    assert(q != NULL);                      //  �ж��Ƿ�ɹ����뵽�ڴ�ռ�
    q->last = -1;                           //  �� last ֵ��ʼ��Ϊ -1
    return q;
}

/* ��Ԫ����ջ */
void PushElement(SeqList *Q, LinkList L)
{
    while(L->next != NULL)
    {
        if(Q->last == MAXSIZE - 1)
        {
            printf("����Ԫ��������");
        }
        else
        {
            Q->A[++Q->last] = L->data;  // �� x ����
            L = L->next;
        }
    }
}


/* ��Ԫ�س�ջ */
datatype PopElement(SeqList *Q)
{
    if(Q->last >= 0)
        return Q->A[Q->last--];
    else
        return '@';
}

/*  �������������Ԫ�� */
void PrintElements(LinkList L)
{
    int i;
    while(L->next != NULL)
    {
        printf("%c", L->data);
        L = L->next;
    }
    printf("\n");
}


/* ��ջ�������µ����� */
int ReverseLinkList(SeqList *Q)
{
    char ch;
    LinkList rear;
    // ����ͷ���
    LinkList p = InitLinkList();
    rear = p;

    // ����������
    while((ch = PopElement(Q)) != '@')
    {
        Node *node = malloc(sizeof(Node));
        node->data = ch;
        node->next = NULL;
        rear->next = node;
        rear = rear->next;
    }
    PrintElements(p);
    return 1;
}
