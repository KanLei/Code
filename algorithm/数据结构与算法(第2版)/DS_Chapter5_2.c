/*
	�����һ���㷨��Ҫ����㷨�Ѷ�������Ҷ��㰴�����ҵ�˳������һ��������
	�������� lchild-rchild ��ʽ�洢������ʱ��Ҷ���� rchild ������ָ�롣

	Tip:
	��Ϊ����ǰ���������������ͺ������������Ҷ�ӽ������˳������ͬ�ģ������Ǵ������ҡ�
	����ĿҪ���ǽ��������е�Ҷ�ӽ�㰴��������˳����һ����������ˣ����Բ������ֱ����е�����һ�ַ���������
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
void CreateLinkListOfLeafs(BiTree T);	/* ��Ҷ�ӽ������һ�������� */

BiTree head, p;  /* ȫ�ֱ�����Ĭ��ֵ */

int main()
{
    BiTree root;

    printf("������������й����������洢�Ķ�����\n");
    printf("����������(0��ʾ��),�磺ABD0G000CE00F00:\n");

    CreateBiTree(&root);

	CreateLinkListOfLeafs(root);

	while(head)
	{
		printf("%c", head->data);
		head = head->rchild;
	}

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



/* ��Ҷ�ӽ������һ�������� */
void CreateLinkListOfLeafs(BiTree T)
{
	if (T != NULL)
	{
		if ((NULL == T->lchild) && (NULL == T->rchild))	/* Ҷ�ӽ�� */
		{
			if (NULL == p)	/* ��һ��Ҷ�ӽ�� */
			{
				head = T;
				p = T;
			}
			else
			{
				p->rchild = T;
				p = T;
			}
		}
		else
		{
			CreateLinkListOfLeafs(T->lchild);
			CreateLinkListOfLeafs(T->rchild);
		}
	}
}
