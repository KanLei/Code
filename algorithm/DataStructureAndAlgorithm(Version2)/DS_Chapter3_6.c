/*
    借助于栈将一个单链表逆置。
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
} SeqList;

/* 定义链表节点结构 */
typedef struct node
{
    datatype data;
    struct node* next;
} Node, *LinkList;

LinkList InitLinkList();                 // 初始化链表
SeqList* InitSeqList();
void PushElement(SeqList *Q, LinkList L); // 将元素入栈
datatype PopElement(SeqList *Q);               // 将元素出栈
void PrintElements(LinkList L);         // 输出所有元素
int ReverseLinkList(SeqList *Q, LinkList result);


int main()
{
    datatype arr[MAXSIZE];
    SeqList *Q = InitSeqList();
    char ch;
    Node *node;
    LinkList rear;
    LinkList result = InitLinkList();

    // 建立头结点
    LinkList p = InitLinkList();
    rear = p;
    // 构建单链表
    printf("\nPlease input the string：");
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

/* 初始化链表 */
LinkList InitLinkList()
{
    LinkList p = malloc(sizeof(Node));  	 //  为 LinkList 分配内存空间
    assert(p != NULL);                       //  判断是否成功申请到内存空间
    p->next = NULL;                          //  将 next 指针初始化为 NULL
    return p;
}

SeqList* InitSeqList()
{
    SeqList *q = malloc(sizeof(SeqList));   //  为 SeqList 分配内存空间
    assert(q != NULL);                      //  判断是否成功申请到内存空间
    q->last = -1;                           //  将 last 值初始化为 -1
    return q;
}

/* 将元素入栈 */
void PushElement(SeqList *Q, LinkList L)
{
	Node* p = L->next;
    while(p != NULL)
    {
        if(Q->last == MAXSIZE - 1)
        {
            printf("栈已满！\n");
        }
        else
        {
            Q->A[++Q->last] = p->data;  // 将 x 插入
            p = p->next;
        }
    }
}


/* 将元素出栈 */
datatype PopElement(SeqList *Q)
{
    if(Q->last >= 0)
        return Q->A[Q->last--];
    else
        return '@';
}

/*  输出链表中所有元素 */
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


/* 出栈并构造新的链表 */
int ReverseLinkList(SeqList *Q, LinkList result)
{
    char ch;
    Node *rear  = result;

    // 构建单链表
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
