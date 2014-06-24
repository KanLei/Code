/*
	给定一棵用二叉链表表示的二叉树，其根指针为 root，试写出求二叉树结点的数目的算法。
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
int CountNodes(BiTree T);	/* 计算结点的个数 */

int main()
{
    BiTree root;

    printf("以先序遍历序列构造二叉链表存储的二叉树\n");
    printf("请输入序列,如：ABD0G000CE00F00:\n");

    CreateBiTree(&root);

    printf("%d", CountNodes(root));		/* 输出结点数目 */

    return 0;
}

/* 以先序遍历序列构造二叉链表存储的二叉树*/
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


/* 计算结点的个数 */
int CountNodes(BiTree T)
{
    if(NULL == T)   return 0;
    return CountNodes(T->lchild) + CountNodes(T->rchild) + 1;
}
