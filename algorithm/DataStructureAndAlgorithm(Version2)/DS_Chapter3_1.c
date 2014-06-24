/*
    �������ͷ�������ͬ���ַ�����Ϊ"����"�����磬"abcddcba"��"qwerewq" �ǻ��ģ�
    "ashgash" ���ǻ��ġ���дһ���㷨�ж϶����һ���� '@' Ϊ���������ַ������Ƿ�Ϊ���ġ�
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

SeqStack* InitSeqList();                // ��ʼ��˳���
void PushElement(SeqStack *L, datatype x); // ��Ԫ����ջ
datatype PopElement(SeqStack *L);               // ��Ԫ�س�ջ
void PrintElements(SeqStack *L);         // �������Ԫ��
int IsPalindrome(const datatype arr[]);           // �Ƿ��ǻ���

int main()
{
    datatype arr[MAXSIZE];

    printf("\nPlease input the string��");
    scanf("%s", arr);

    printf(IsPalindromeUsePoint(arr) ? "�ǻ���\n" : "���ǻ���\n");

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
    assert(L->last != -1);  // ջ�ѿ�
    return L->A[L->last--];
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


/* �ж��Ƿ��ǻ��ģ�����ջ */
int IsPalindrome(const datatype arr[])
{
    int i;
    SeqStack *p = InitSeqList();

    for(i = 0; arr[i] != '@'; i++)
    {
        PushElement(p, arr[i]);    // ��Ԫ����ջ
    }

    // ��Ԫ�س�ջ�������ַ������бȽ�
    for(i = 0; arr[i] != '@'; i++)
    {
        if(PopElement(p) != arr[i])
            return 0;  // ���ǻ���
    }
    return 1;  // �ǻ���
}

/* �ж��Ƿ��ǻ��ģ�����ָ�� */
int IsPalindromeUsePoint(const char* str)
{
    const char* start = str;
    const char* end = str;
    while(*end != '@')  end++;
    for(--end; (start < end) && (*start == *end); --end, ++start)
        ;
    return start < end ? 0 : 1;
}
