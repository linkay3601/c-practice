/**
 * 字符串转整型数（简化版）
 */
#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
int atoi();


int main()
{
    char string[] = "-234433.23442";
    int n;

    n = atoi(string);
    printf("string to int number is: %d\n", n);
}


/* 字符串转整型数（简化版）*/
int atoi(char s[])
{
    return (int) atof(s);
}


/* 字符串转浮点型数 */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    return sign * val / power;
}
