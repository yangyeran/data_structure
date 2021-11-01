#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
bool isValid(char* s) {
    char* p = s;
    int count = 0;
    while (*p)
    {
        count++;
        p++;
    }
    //计算有多少个字符,就开辟一个多长的数组
    char* arr = (char*)malloc(sizeof(char) * count);
    int i = -1;
    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            ++i;
            arr[i] = *s;
            s++;
        }
        else
        {
            if (i == -1)
                return false;
            if ((arr[i] == '(') && *s == ')'
                || (arr[i] == '{') && *s == '}'
                || (arr[i] == '[') && *s == ']')
            {
                s++;
                i--;
            }
            else
                return false;
        }
    }
    //跳出来时*s='\0'
    if (i != -1)
    {
        free(arr);
        return false;
    }
    else
    {
        free(arr);
        return true;
    }
}