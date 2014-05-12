#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *lchild, *rchild;
} BiNode, *BiTree;


/* 先序次序构造二叉链表 */
/* ABD0G000CE00F00 */
void CreateBiTree(BiTree *T)
{
    char ch;
    scanf("%c", &ch);
    if(ch == '0')
    {
        *T = NULL;
    }
    else
    {
        *T = malloc(sizeof(BiNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}


/* 前序遍历 */
void PreOrder(BiTree T)
{
    if(T == NULL)
        return;
    else
    {
        printf("%c", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/* 中序遍历 */
void InOrder(BiTree T)
{
    if(T == NULL)
        return;
    else
    {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}


/* 后序遍历 */
void PostOrder(BiTree T)
{
    if(T == NULL)
        return;
    else
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}

int main()
{
    BiTree T;
    CreateBiTree(&T);

    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);

    return 0;
}
