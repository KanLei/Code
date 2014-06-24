/*
	已知带头结点的单链表 L 中的结点是按整数值递增排列的，试写一算法，将值为 x 的结点
	插入到表 L 中，使得 L 仍然递增有序，并且分析算法的时间复杂度。
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
void PrintElement(LinkList L);  /* 输出单链表 */

int main()
{
	datatype num;
	LinkList L = InitLinklist();

	do
	{
		printf("Please input a number to insert: ");
		if((scanf("%d", &num)) != 1)
			break;
		else
		{
			InsertElement(L, num);
			PrintElement(L);
		}
	}while(1);
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
