/*
    ����һ�ö��������ʾ�Ķ����������ָ��Ϊ root����д��������������н������������໥�������㷨��
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char datatype;

/* �������н�� */
typedef struct binode
{
    datatype data;
    struct binode *lchild, *rchild;
} BiNode, *BiTree;

void CreateBiTree(BiTree *T);   /* ������������й����������洢�Ķ�����*/
void PreOrder(BiTree T);	/* ��������������� */
void ExchangeSubTree(BiTree T);    /* ������������ */

BiTree head, p;  /* ȫ�ֱ�����Ĭ��ֵ */

int main()
{
    BiTree root;

    printf("������������й����������洢�Ķ�����\n");
    printf("����������(0��ʾ��),�磺ABD0G000CE00F00:\n");

    CreateBiTree(&root);

	ExchangeSubTree(root);

	PreOrder(root);

    return 0;
}

/* ������������й����������洢�Ķ����� */
void CreateBiTree(BiTree *T)
{
    char ch;

    scanf("%c", &ch);
    if(ch == '0')   *T = NULL;  /* ����0ʱ��������ÿ� */
    else
    {
        *T = malloc(sizeof(BiNode));
        assert(*T != NULL);
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}

/* ��������������� */
void PreOrder(BiTree T)
{
	if(NULL == T)	return;
	printf("%c  ", T->data);
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}


/* ������������ */
void ExchangeSubTree(BiTree T)
{
	BiTree p;
    if (NULL == T)  return;
    ExchangeSubTree(T->lchild);
    ExchangeSubTree(T->rchild);

	/* ������������ */
    p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
}

