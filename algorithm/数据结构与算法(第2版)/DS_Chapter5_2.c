/*
	请设计一个算法，要求改算法把二叉树的叶结点按从左到右的顺序链成一个单链表。
	二叉树按 lchild-rchild 方式存储，链接时用叶结点的 rchild 域存放链指针。

	Tip:
	因为不论前序遍历、中序遍历和后序遍历，访问叶子结点的相对顺序都是相同的，即都是从左至右。
	而题目要求是将二叉树中的叶子结点按从左至右顺序建立一个单链表，因此，可以采用三种遍历中的任意一种方法遍历。
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char datatype;

/* 定义树中结点 */
typedef struct binode
{
    datatype data;
    struct binode *lchild, *rchild;
} BiNode, *BiTree;

void CreateBiTree(BiTree *T);   /* 以先序遍历序列构造二叉链表存储的二叉树*/
void CreateLinkListOfLeafs(BiTree T);	/* 将叶子结点链成一个单链表 */

BiTree head, p;  /* 全局变量有默认值 */

int main()
{
    BiTree root;

    printf("以先序遍历序列构造二叉链表存储的二叉树\n");
    printf("请输入序列(0表示空),如：ABD0G000CE00F00:\n");

    CreateBiTree(&root);

	CreateLinkListOfLeafs(root);

	while(head)
	{
		printf("%c", head->data);
		head = head->rchild;
	}

    return 0;
}

/* 以先序遍历序列构造二叉链表存储的二叉树 */
void CreateBiTree(BiTree *T)
{
    char ch;

    scanf("%c", &ch);
    if(ch == '0')   *T = NULL;  /* 读入0时，将结点置空 */
    else
    {
        *T = malloc(sizeof(BiNode));
        assert(*T != NULL);
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}



/* 将叶子结点链成一个单链表 */
void CreateLinkListOfLeafs(BiTree T)
{
	if (T != NULL)
	{
		if ((NULL == T->lchild) && (NULL == T->rchild))	/* 叶子结点 */
		{
			if (NULL == p)	/* 第一个叶子结点 */
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
