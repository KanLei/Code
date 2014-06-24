/*
    �������в���ֵΪ x �Ľ�㣬����ƴ�ӡֵΪ x �Ľ����������Ƚ���㷨��
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
void PreOrder(BiTree T);    /* ��������������� */
int PrintAncestry(BiTree T, datatype x);    /* ������Ƚ�� */

BiTree head, p;  /* ȫ�ֱ�����Ĭ��ֵ */

int main()
{
    BiTree root;

    printf("������������й����������洢�Ķ�����\n");
    printf("����������(0��ʾ��),�磺ABD0G000CE00F00:\n");

    CreateBiTree(&root);

    PrintAncestry(root, 'G');

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
    if(NULL == T)   return;
    printf("%c  ", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}


/* ������Ƚ�� */
int PrintAncestry(BiTree T, datatype x)
{
    if(NULL == T)  return 0;
    if(x == T->data)  return 1;
	if(1 == PrintAncestry(T->lchild, x) || 1 == PrintAncestry(T->rchild, x))
	{
		printf("%c  ",T->data);
		return 1;
	}
	return 0;
}

