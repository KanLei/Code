/*
    给定一棵二叉链表表示的二叉树，其根指针为 root，试写出求二叉树的深度的算法。
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
int GetHeight(BiTree T);    /* 获取树的深度 */

BiTree head, p;  /* 全局变量有默认值 */

int main()
{
    BiTree root;

    printf("以先序遍历序列构造二叉链表存储的二叉树\n");
    printf("请输入序列(0表示空),如：ABD0G000CE00F00:\n");

    CreateBiTree(&root);

	printf("%d", GetHeight(root));

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



/* 获取树的深度 */
int GetHeight(BiTree T)
{
    int hl, hr;
    hl = hr = 0;

    if (NULL == T)  return 0;
    hl = GetHeight(T->lchild);
    hr = GetHeight(T->rchild);

    return (hl > hr ? hl : hr) + 1;
}

