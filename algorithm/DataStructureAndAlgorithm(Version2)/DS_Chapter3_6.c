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
int ReverseLinkList(SeqList *Q, LinkList result);


int main()
{
    datatype arr[MAXSIZE];
    SeqList *Q = InitSeqList();
    char ch;
    Node *node;
    LinkList rear;
    LinkList result = InitLinkList();

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
    ReverseLinkList(Q, result);
	PrintElements(result);

    return 0;
}

/* ��ʼ������ */
LinkList InitLinkList()
{
    LinkList p = malloc(sizeof(Node));  	 //  Ϊ LinkList �����ڴ�ռ�
    assert(p != NULL);                       //  �ж��Ƿ�ɹ����뵽�ڴ�ռ�
    p->next = NULL;                          //  �� next ָ���ʼ��Ϊ NULL
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
	Node* p = L->next;
    while(p != NULL)
    {
        if(Q->last == MAXSIZE - 1)
        {
            printf("ջ������\n");
        }
        else
        {
            Q->A[++Q->last] = p->data;  // �� x ����
            p = p->next;
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
	Node* p = L->next;
    while(NULL != p)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}


/* ��ջ�������µ����� */
int ReverseLinkList(SeqList *Q, LinkList result)
{
    char ch;
    Node *rear  = result;

    // ����������
    while((ch = PopElement(Q)) != '@')
    {
        Node *node = malloc(sizeof(Node));
        node->data = ch;
        node->next = NULL;
        rear->next = node;
        rear = rear->next;
    }

    return 1;
}
