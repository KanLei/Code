/*
    ����һ�ö��������ʾ�Ķ����������ָ��Ϊ root����д�������������ȵ��㷨��
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
int GetHeight(BiTree T);    /* ��ȡ������� */

BiTree head, p;  /* ȫ�ֱ�����Ĭ��ֵ */

int main()
{
    BiTree root;

    printf("������������й����������洢�Ķ�����\n");
    printf("����������(0��ʾ��),�磺ABD0G000CE00F00:\n");

    CreateBiTree(&root);

	printf("%d", GetHeight(root));

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



/* ��ȡ������� */
int GetHeight(BiTree T)
{
    int hl, hr;
    hl = hr = 0;

    if (NULL == T)  return 0;
    hl = GetHeight(T->lchild);
    hr = GetHeight(T->rchild);

    return (hl > hr ? hl : hr) + 1;
}

