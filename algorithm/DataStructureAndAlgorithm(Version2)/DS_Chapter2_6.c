/*
	��֪��ͷ���ĵ����� L �еĽ���ǰ�����ֵ�������еģ���дһ�㷨����ֵΪ x �Ľ��
	���뵽�� L �У�ʹ�� L ��Ȼ�������򣬲��ҷ����㷨��ʱ�临�Ӷȡ�
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
void PrintElement(LinkList L);  /* ��������� */

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
