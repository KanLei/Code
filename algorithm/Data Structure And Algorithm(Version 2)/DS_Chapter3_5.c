/*
    ���һ���㷨�б�һ���������ʽ��Բ�����Ƿ���ȷ��ԡ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100   //  �����������󳤶�
typedef char datatype; //  ������������


/* ����ṹ�����ڴ������͵�ǰ������Ԫ�صĸ��� */
typedef struct
{
    datatype A[MAXSIZE];
    int last;
} SeqStack;

SeqStack* InitSeqList();                 // ��ʼ��˳���
void PushElement(SeqStack *L, datatype x); // ��Ԫ����ջ
datatype PopElement(SeqStack *L);               // ��Ԫ�س�ջ
void PrintElements(SeqStack *L);         // �������Ԫ��
int IsParenthesisMatch(const datatype arr[]);           // �����Ƿ�ƥ��

int main()
{
    datatype ch;
    int i;
    datatype arr[MAXSIZE];

    printf("\nPlease input the string��");
    scanf("%s", arr);

    printf(IsParenthesisMatch(arr) ? "ƥ��\n" : "��ƥ��\n");

    return 0;
}

/* ��ʼ��˳��� */
SeqStack* InitSeqList()
{
    SeqStack *p = malloc(sizeof(SeqStack));   //  Ϊ SeqList �����ڴ�ռ�
    assert(p != NULL);                      //  �ж��Ƿ�ɹ����뵽�ڴ�ռ�
    p->last = -1;                           //  �� last ֵ��ʼ��Ϊ -1
    return p;
}


/* ��Ԫ����ջ */
void PushElement(SeqStack *L, datatype x)
{
    int index;
    if(L->last == MAXSIZE - 1)
    {
        printf("����Ԫ��������");
    }
    else
    {
        L->A[++L->last] = x;  // �� x ����
    }
}


/* ��Ԫ�س�ջ */
datatype PopElement(SeqStack *L)
{
    if(L->last >= 0)
        return L->A[L->last--];
    else
        return '@';
}

/*  �������Ԫ�� */
void PrintElements(SeqStack *L)
{
    int i;
    for(i = 0; i <= L->last; i++)
    {
        printf("%c", L->A[i]);
    }
    printf("\n");
}


/* �ж������Ƿ�ƥ�� */
int IsParenthesisMatch(const datatype arr[])
{
    int i;
    SeqStack *p = InitSeqList();

    for(i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == '(')
            PushElement(p, arr[i]);    // ��Ԫ����ջ
    }

    // ��Ԫ�س�ջ�������ַ������бȽ�
    for(i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == ')')
            if(PopElement(p) != '(')
                return 0;
    }

    // �ж�ջ���Ƿ񻹴���������
    if(PopElement(p) != '@')
	{
		return 0;  // ��ƥ��
	}
    return 1;  // ƥ��
}
