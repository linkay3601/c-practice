#include <stdio.h>

int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

int main()
{
    srand(32432);
    printf("%d\n", rand());
}


/* 随机数发生器 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}


void srand(unsigned int seed)
{
    next = seed;
}
