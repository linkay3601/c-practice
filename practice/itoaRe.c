/**
 * 数字转字符串（递归实现）
 */
#include <stdio.h>

void printd(int n);


int main()
{
    int n = -12334;

    printd(n);
}


/* 数字转字符串（递归实现）*/
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);

    putchar(n % 10 + '0');
}
