#include <stdio.h>  // 定义 getchar 函数
#include <ctype.h>  // 定义 tolower 函数


int main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(tolower(c));
    return 0;
}
