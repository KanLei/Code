/*
    ����һ�ö��������ʾ�Ķ����������ָ��Ϊ root����д��������������Ĳ������㷨��
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
void PrintLevel(BiTree T,int n);    /* ��������Ĳ��� */

BiTree head, p;  /* ȫ�ֱ�����Ĭ��ֵ */

int main()
{
    BiTree root;

    printf("������������й����������洢�Ķ�����\n");
    printf("����������(0��ʾ��),�磺ABD0G000CE00F00:\n");

    CreateBiTree(&root);

	PrintLevel(root, 1);

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



/* ��������Ĳ��� */
void PrintLevel(BiTree T, int n)
{
    if (NULL == T)  return;
    printf("��㣺%c ����Ϊ��%d\n", T->data, n);
    PrintLevel(T->lchild, n + 1);
    PrintLevel(T->rchild, n + 1);
}

