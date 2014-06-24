/*
    给定一棵二叉链表表示的二叉树，其根指针为 root，试写出求二叉树中所有结点的左右子树相互交换的算法。
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
void PreOrder(BiTree T);	/* 先序遍历二叉链表 */
void ExchangeSubTree(BiTree T);    /* 交换左右子树 */

BiTree head, p;  /* 全局变量有默认值 */

int main()
{
    BiTree root;

    printf("以先序遍历序列构造二叉链表存储的二叉树\n");
    printf("请输入序列(0表示空),如：ABD0G000CE00F00:\n");

    CreateBiTree(&root);

	ExchangeSubTree(root);

	PreOrder(root);

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
	if(NULL == T)	return;
	printf("%c  ", T->data);
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}


/* 交换左右子树 */
void ExchangeSubTree(BiTree T)
{
	BiTree p;
    if (NULL == T)  return;
    ExchangeSubTree(T->lchild);
    ExchangeSubTree(T->rchild);

	/* 交换左右子树 */
    p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
}

