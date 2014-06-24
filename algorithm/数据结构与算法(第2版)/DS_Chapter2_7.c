/*
	�������������򣨵������ĵ����� A �� B����д�㷨�����Ǻϲ���һ������ C
	�����ı��������ԡ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int datatype;

// ������
typedef struct linklist{
	datatype data;
	struct linklist* next;
}Node, *LinkList;

LinkList InitLinklist();  /* ��ʼ�������� */
void InsertElement(LinkList L, datatype x);  /* ����Ԫ�� */
void MergeLinkList(LinkList A, LinkList B, LinkList C);	/* �ϲ������������� */
void PrintElement(LinkList L);  /* ��������� */

int main()
{
	datatype num;
	LinkList A = InitLinklist();
	LinkList B = InitLinklist();
	LinkList C = InitLinklist();

	//  �������� A
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
	getchar();  // ���ڽ��ջ������ַ�

	// �������� B
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

	MergeLinkList(A, B, C);   /* �ϲ����� */

	printf("\n�ϲ��������:\n");
	PrintElement(C);  /* ����ϲ�������� */

    return 0;
}

/* ��ʼ�������� */
LinkList InitLinklist()
{
	LinkList L = malloc(sizeof(Node));
	assert(L != NULL);
	L->next = NULL;
	return L;
}

/* ����Ԫ�� */
void InsertElement(LinkList L, datatype x)
{
	LinkList l = L;
	Node *p = malloc(sizeof(Node));
	assert(p!=NULL);
	p->data = x;
	p->next = NULL;

	while(l->next)
	{
		if(x <= l->next->data)	/* �ҵ������λ�� */
		{
			p->next = l->next;
			l->next = p;
			return; /* ���� */
		}
		l = l->next;
	}
	l->next = p;  /* ���δ�ҵ����ʵ�λ�ã�����ӵ�������ĩβλ�� */
}

/* �ϲ����������������� */
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

/* ��������� */
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
