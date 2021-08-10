/**
 * 简单 grep 命令实现
 */
#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
int strindex(char s[], char t[]);

char pattern[] = "ould";


int main()
{
    char line[MAXLINE];
    int found = 0;

    while (getLine(line, MAXLINE))
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }

    return found;
}


/* 获取下一行输入 */
int getLine(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}


/* 字符串中匹配指定模式 */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}
