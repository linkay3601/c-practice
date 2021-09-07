#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    return 0;
}

/* fgets 实现获取输入行 */
int getLine(char *line, int max)
{
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}
