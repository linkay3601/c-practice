#include <stdio.h>

void strCat(char s[], char t[]);


int main()
{
    char  world[] = "world";
    char string[] = "hello,";

    strCat(string, world);
    printf("%s\n", string);
}


/* 字符数组连接操作 */
void strCat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i++] != '\0')
        ;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
