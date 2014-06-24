/*
  ��Ŀ��
  ��֪һ˳���A����Ԫ��ֵ�ǵݼ��������У�
  ��дһ���㷨ɾ��˳������ظ���Ԫ�ء�
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
SeqList* DeleteRepeatedElement(SeqList *L);  // ɾ���ظ���Ԫ��
void Delete2(SeqList *L);
void Delete3(SeqList *L);
void Delete4(SeqList* L);

int main()
{
    int x;
    SeqList *p = InitSeqList();


    printf("\nPlease input the x��");
    while(scanf("%d", &x))
    {
        InsertElement(p, x);    // ����Ԫ��

        PrintElements(p);       //  �ٴ��������Ԫ��

        printf("\nPlease input the x��");
    }

    //PrintElements(DeleteRepeatedElement(p));  // ɾ���ظ�Ԫ�ز����
    Delete4(p);
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

// ����1:������һ�����Ա����洢
/* ɾ�������ֵ */
SeqList* DeleteRepeatedElement(SeqList *L)
{
    int i;
    SeqList *seq = InitSeqList();
    seq->A[++seq->last] = L->A[0];  // ȡ��һ��Ԫ�ص�ֵ��ŵ�seq��

    for(i = 1; i <= L->last; i++)
    {
        if(L->A[i] != seq->A[seq->last])
        {
            seq->A[++seq->last] = L->A[i];
        }
    }
    free(L->A);
    return seq;
}


// ����2
/* ɾ�������ֵ */
void Delete2(SeqList *L)
{
    int i, j, k, n;
    for(i = 0; i < L->last; i++)
    {
        k = i + 1;
        while(k <= L->last && L->A[i] == L->A[k])
        {
            k++;
        }

        n = k - i - 1;  // �����ظ�Ԫ�صĸ���
        for(j = k; j <= L->last; j++)
            L->A[j - n] = L->A[j];

        L->last = L->last - n;
    }
}

// ����3
void Delete3(SeqList *L)
{
    int i, j;
    for(i = 0, j = 1; j <= L->last; j++)
    {
        if(L->A[i] != L->A[j])
            L->A[++i] = L->A[j];
    }
    L->last = i;
}

void Delete4(SeqList* L)
{
	//int k = 0;
	int i, j;
	for(i=0;i< L->last;i++)
	{
		if(L->A[i] == L->A[i+1])
		{
			//k++;
			for(j=i; j< L->last; j++)
			{
				L->A[j] = L->A[j+1];
			}
			i--;
			L->last--;
		}
	}
	//L->last = L->last - k;
}
