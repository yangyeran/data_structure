#pragma once
#include <stdio.h>
#define MaxSize 100
typedef struct {		//定义顺序串
	char data[MaxSize];		//定义可容纳MaxSize个字符的空间
	int length;            //标记当前实际串长
} SqString;
//串的赋值
void StrAssign(SqString& s, char cstr[]);
//串的拷贝
void StrCopy(SqString& s, SqString t);
//比较两个串是否相等
bool StrEqual(SqString s, SqString t);
//求串长
int StrLength(SqString s);
//截取子串
SqString SubStr(SqString s, int i, int j);
//插入子串
SqString InsStr(SqString s1, int i, SqString s2);
//删除子串
SqString DelStr(SqString s, int i, int j);
//替换子串
SqString RepStr(SqString s, int i, int j, SqString t);
//输出串
void DispStr(SqString s);
//串的链接
SqString Concat(SqString s, SqString t);
//实验四  串的基本操作
//【实验目的】
//1．掌握串的顺序存储表示。
//2．掌握顺序串的基本操作，包括创建、查找、截取、替换等算法。
//【实验内容】
//编写程序sqstring.cpp，实现顺序串的各种基本运算，并在此基础上设计主程序main.cpp，完成如下功能：
//1．建立串s = “abcdefghijklmn” 和串s1 = “123”；
//2．输出串s；
//3．输出串s的长度；
//4．在串s的第9个字符位置插入串s1而产生串s2；
//5．输出串s2；
//6．删除串s第2个字符开始的5个字符而产生串s2；
//7．输出串s2；
//8．将串s第2个字符开始的5个字符替换成串s1而产生串s2；
//9．输出串s2；
//10．提取串s的第2个字符开始的10个字符而产生串s3；
//11．输出串s3；
//12．将串s1和串s2连接起来产生串s4；
//13．输出串s4。