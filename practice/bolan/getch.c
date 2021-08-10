#include "calc.h"
#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZ];  // ungetch 的缓存
static int bufp = 0;      // 缓存的下一个空闲位置


/* 反读 字符 */
int getch(void)
{
    return (bufp > 0)? buf[--bufp]: getchar();
}


void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
