/*
	����һ���ö��������ʾ�Ķ����������ָ��Ϊ root����д���������������Ŀ���㷨��
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
int CountNodes(BiTree T);	/* ������ĸ��� */

int main()
{
    BiTree root;

    printf("������������й����������洢�Ķ�����\n");
    printf("����������,�磺ABD0G000CE00F00:\n");

    CreateBiTree(&root);

    printf("%d", CountNodes(root));		/* ��������Ŀ */

    return 0;
}

/* ������������й����������洢�Ķ�����*/
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


/* ������ĸ��� */
int CountNodes(BiTree T)
{
    if(NULL == T)   return 0;
    return CountNodes(T->lchild) + CountNodes(T->rchild) + 1;
}
