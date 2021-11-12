#pragma once
#include <stdio.h>
#define MaxSize 100
typedef struct {		//����˳��
	char data[MaxSize];		//���������MaxSize���ַ��Ŀռ�
	int length;            //��ǵ�ǰʵ�ʴ���
} SqString;
//���ĸ�ֵ
void StrAssign(SqString& s, char cstr[]);
//���Ŀ���
void StrCopy(SqString& s, SqString t);
//�Ƚ��������Ƿ����
bool StrEqual(SqString s, SqString t);
//�󴮳�
int StrLength(SqString s);
//��ȡ�Ӵ�
SqString SubStr(SqString s, int i, int j);
//�����Ӵ�
SqString InsStr(SqString s1, int i, SqString s2);
//ɾ���Ӵ�
SqString DelStr(SqString s, int i, int j);
//�滻�Ӵ�
SqString RepStr(SqString s, int i, int j, SqString t);
//�����
void DispStr(SqString s);
//��������
SqString Concat(SqString s, SqString t);
//ʵ����  ���Ļ�������
//��ʵ��Ŀ�ġ�
//1�����մ���˳��洢��ʾ��
//2������˳�򴮵Ļ����������������������ҡ���ȡ���滻���㷨��
//��ʵ�����ݡ�
//��д����sqstring.cpp��ʵ��˳�򴮵ĸ��ֻ������㣬���ڴ˻��������������main.cpp��������¹��ܣ�
//1��������s = ��abcdefghijklmn�� �ʹ�s1 = ��123����
//2�������s��
//3�������s�ĳ��ȣ�
//4���ڴ�s�ĵ�9���ַ�λ�ò��봮s1��������s2��
//5�������s2��
//6��ɾ����s��2���ַ���ʼ��5���ַ���������s2��
//7�������s2��
//8������s��2���ַ���ʼ��5���ַ��滻�ɴ�s1��������s2��
//9�������s2��
//10����ȡ��s�ĵ�2���ַ���ʼ��10���ַ���������s3��
//11�������s3��
//12������s1�ʹ�s2��������������s4��
//13�������s4��