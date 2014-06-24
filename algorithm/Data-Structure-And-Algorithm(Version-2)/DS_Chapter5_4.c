/*
    给定一棵二叉链表表示的二叉树，其根指针为 root，试写出求二叉树各结点的层数的算法。
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
void PrintLevel(BiTree T,int n);    /* 输出各结点的层数 */

BiTree head, p;  /* 全局变量有默认值 */

int main()
{
    BiTree root;

    printf("以先序遍历序列构造二叉链表存储的二叉树\n");
    printf("请输入序列(0表示空),如：ABD0G000CE00F00:\n");

    CreateBiTree(&root);

	PrintLevel(root, 1);

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



/* 输出各结点的层数 */
void PrintLevel(BiTree T, int n)
{
    if (NULL == T)  return;
    printf("结点：%c 层数为：%d\n", T->data, n);
    PrintLevel(T->lchild, n + 1);
    PrintLevel(T->rchild, n + 1);
}

