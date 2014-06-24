/*
	假设两个已排序（递增）的单链表 A 和 B，编写算法将它们合并成一个链表 C
	而不改变其排序性。
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int datatype;

// 定义结点
typedef struct linklist{
	datatype data;
	struct linklist* next;
}Node, *LinkList;

LinkList InitLinklist();  /* 初始化单链表 */
void InsertElement(LinkList L, datatype x);  /* 插入元素 */
void MergeLinkList(LinkList A, LinkList B, LinkList C);	/* 合并两个有序链表 */
void PrintElement(LinkList L);  /* 输出单链表 */

int main()
{
	datatype num;
	LinkList A = InitLinklist();
	LinkList B = InitLinklist();
	LinkList C = InitLinklist();

	//  构造链表 A
	do
	{
		printf("Please input a number to insert linklist A: ");
		if((scanf("%d", &num)) != 1)
			break;
		else
		{
			InsertElement(A, num);
			PrintElement(A);
		}
	}while(1);
	printf("\n");
	getchar();  // 用于接收缓冲区字符

	// 构造链表 B
	do
	{
		printf("Please input a number to insert linklist B: ");
		if((scanf("%d", &num)) != 1)
			break;
		else
		{
			InsertElement(B, num);
			PrintElement(B);
		}
	}while(1);

	MergeLinkList(A, B, C);   /* 合并链表 */

	printf("\n合并后的链表:\n");
	PrintElement(C);  /* 输出合并后的链表 */

    return 0;
}

/* 初始化单链表 */
LinkList InitLinklist()
{
	LinkList L = malloc(sizeof(Node));
	assert(L != NULL);
	L->next = NULL;
	return L;
}

/* 插入元素 */
void InsertElement(LinkList L, datatype x)
{
	LinkList l = L;
	Node *p = malloc(sizeof(Node));
	assert(p!=NULL);
	p->data = x;
	p->next = NULL;

	while(l->next)
	{
		if(x <= l->next->data)	/* 找到插入的位置 */
		{
			p->next = l->next;
			l->next = p;
			return; /* 返回 */
		}
		l = l->next;
	}
	l->next = p;  /* 如果未找到合适的位置，则添加到单链表末尾位置 */
}

/* 合并两个递增有序链表 */
void MergeLinkList(LinkList A, LinkList B, LinkList C)
{
	LinkList p = A->next;
	LinkList q = B->next;
	while(p && q)
	{
		if(p->data <= q->data)
		{
			C->next = p;
			C = C->next;
			p = p->next;
		}
		else
		{
			C->next = q;
			C = C->next;
			q = q->next;
		}
	}
	if(p)
	{
		C->next = p;
	}
	if(q)
	{
		C->next = q;
	}
}

/* 输出单链表 */
void PrintElement(LinkList L)
{
	LinkList p = L->next;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
