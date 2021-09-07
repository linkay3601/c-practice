/**
 * 函数指针实现指针数组排序
 */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    // 可排序的最大行数
char *lineptr[MAXLINES]; // 指向每一行的指针数组

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qSort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char const *argv[])
{
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        if (numeric)
            qSort((void **)lineptr, 0, nlines - 1,
                  (int (*)(void *, void *))(numcmp));
        else
            qSort((void **)lineptr, 0, nlines - 1,
                  (int (*)(void *, void *))(strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input to big to sort\n");
        return 0;
    }
}

/* -------------------------------------------------------------------------- */
void swap(void *v[], int, int);

void qSort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qSort(v, left, last - 1, comp);
    qSort(v, last + 1, right, comp);
}

/* -------------------------------------------------------------------------- */
#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* -------------------------------------------------------------------------- */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* -------------------------------------------------------------------------- */
#define MAXLEN 1000 // 输入行的最大长度
int getLine(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

int getLine(char s[], int lim)
{
    int c;
    int i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c; // 字符数组赋值
    }
    if (c == '\n')
    {
        s[i] = c; // 紧接添加换行符
        ++i;
    }
    s[i] = '\0'; // 结尾添加字符数组结束符
    return i;
}

#define ALLOCSIZE 10000 // 可用的空间

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
/* 分配空间 */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return 0;
    }
}

/* -------------------------------------------------------------------------- */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}
