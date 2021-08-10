#define ALLOCSIZE 10000  // 可用的空间

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;


/* 分配空间 */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    } else
    {
        return 0;
    }
}


/* 释放空间 */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
