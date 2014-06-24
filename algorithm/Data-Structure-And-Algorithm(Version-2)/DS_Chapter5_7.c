/*
    二叉树中查找值为 x 的结点，试设计打印值为 x 的结点的所有祖先结点算法。
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
void PreOrder(BiTree T);    /* 先序遍历二叉链表 */
int PrintAncestry(BiTree T, datatype x);    /* 输出祖先结点 */

BiTree head, p;  /* 全局变量有默认值 */

int main()
{
    BiTree root;

    printf("以先序遍历序列构造二叉链表存储的二叉树\n");
    printf("请输入序列(0表示空),如：ABD0G000CE00F00:\n");

    CreateBiTree(&root);

    PrintAncestry(root, 'G');

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

/* 先序遍历二叉链表 */
void PreOrder(BiTree T)
{
    if(NULL == T)   return;
    printf("%c  ", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}


/* 输出祖先结点 */
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

