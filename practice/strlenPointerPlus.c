#include <stdio.h>

int strLen(char *s);


int main()
{
    char string[] = "hello, linkay";
    printf("the char array length is: %d\n", strLen(string));
}


/* 计算字符数组（字符串）的长度（指针进阶版）*/
int strLen(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}
