#include <stdarg.h>  // 定义了变长参数的一些规则
#include <stdio.h>

void miniprintf(char *fmt, ...);

int main()
{
    char *name = "Linkay";
    int age = 18;
    double height = 1.88;

    miniprintf("Hello, I'm %s. My age is %d and height is %f", name, age, height);
}


void miniprintf(char *fmt, ...)
{
    va_list ap;  // 依次引用所有未命名的参数的变量
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);  // 初始化 ap 指向第一个无名参数
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);  // 返回一个无名参数，并将 ap 指向下一个无名参数
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);  // 结束时清理一下 ap
}
