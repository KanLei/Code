/*
  ��Ŀ��
  дһ���㷨����һ��������˳���A��ɾ��ֵ��x~y(x <= y)֮�������Ԫ�أ�
  Ҫ���Խϸߵ�Ч����ʵ�֡�
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100   //  �����������󳤶�
typedef int datatype; //  ������������


/* ����ṹ�����ڴ������͵�ǰ������Ԫ�صĸ��� */
typedef struct
{
    datatype A[MAXSIZE];
    int last;
} SeqList;

SeqList* InitSeqList();                 // ��ʼ��˳���
void InsertElement(SeqList *L, int x);  // ����Ԫ��
void PrintElements(SeqList *L);         // �������Ԫ��
void DeleteElementBetweenXandY(SeqList *L, datatype x, datatype y);  //  ɾ��x~y֮���Ԫ��
void Delete2(SeqList *L, datatype x, datatype y);

int main()
{
    int x;
    SeqList *p = InitSeqList();


    printf("\nPlease input the element��");
    while(scanf("%d", &x))
    {
        InsertElement(p, x);    // ����Ԫ��

        PrintElements(p);       //  �ٴ��������Ԫ��

        printf("\nPlease input the element��");
    }

    //DeleteElementBetweenXandY(p, 2, 6);
    Delete2(p, 2, 6);
    PrintElements(p);

    return 0;
}

/* ��ʼ��˳��� */
SeqList* InitSeqList()
{
    SeqList *p = malloc(sizeof(SeqList));   //  Ϊ SeqList �����ڴ�ռ�
    assert(p != NULL);                      //  �ж��Ƿ�ɹ����뵽�ڴ�ռ�
    p->last = -1;                           //  �� last ֵ��ʼ��Ϊ -1
    return p;
}


/* ����Ԫ�� */
void InsertElement(SeqList *L, datatype x)
{
    int index;
    if(L->last == MAXSIZE - 1)
    {
        printf("����Ԫ��������");
    }
    else
    {
        index = L->last;

        /*�Ӻ���ǰ�������飬ֻҪ����Ԫ��ֵ����Ҫ�����Ԫ��ֵ���ͰѸ�Ԫ�������ƶ�һλ*/
        while(index > -1 && L->A[index] > x)
        {
            L->A[index + 1] = L->A[index];
            index--;
        }
        L->A[++index] = x;  // �� x ����
        L->last++;          // �޸� last ��ֵ
    }
}


/*  �������Ԫ�� */
void PrintElements(SeqList *L)
{
    int i;
    for(i = 0; i <= L->last; i++)
    {
        printf("%d  ", L->A[i]);
    }
    printf("\n");
}

// ����1
/* ɾ��x~y֮���Ԫ�� */
void DeleteElementBetweenXandY(SeqList *L, datatype x, datatype y)
{
    datatype *p , *q;
    int i, num = -1;

    p = q = L->A;
    for(i = 0; i <= L->last; i++, q++)
    {
        if(*q < x || *q > y)
        {
            *p++ = *q;
            num++;  // ��¼Ԫ�صĸ���
        }
    }
    L->last = num;
}


// ����2
/* ɾ��x~y֮���Ԫ�� */
void Delete2(SeqList *L, datatype x, datatype y)
{
    int i, n;

    for(i = n = 0; i <= L->last; i++)
    {
        if(L->A[i] >= x && L->A[i] <= y)
            n++;
        else
            L->A[i - n] = L->A[i];
    }
    L->last = i - n - 1;	// ���� i ��ȥ��Χ�ڵĸ��� n
}
