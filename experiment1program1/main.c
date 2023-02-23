/* 文件名: Subject No.1 - program No.1
创建人: 宗晴
描述: 输出各种变量的值和该变量所占字节数 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.1 - Program No.1\n\n");//文件信息


    char a;
    int b;
    short int c;
    float d;
    double e;//定义五个不同类型的变量


    printf("Please input char a:");
    while (!scanf("%c", &a) || getchar() != '\n')//防止类型错误或者输入多个字符
    {
        while (getchar() != '\n');
        printf("input data error,please input another data:");
    }//要求输入字符型变量a，同时防止非法输入
    printf("char a=%c,size of char is %d\n", a, sizeof(a));//输出字符型变量a的值和该变量所占字节数

    printf("Please input int b:");
    while (!scanf("%d", &b) || getchar() != '\n')//防止类型错误或者输入多个字符
   {
       while (getchar() != '\n');
       printf("input data error,please input another data:");
   }//要求输入整型变量b，同时防止非法输入
    printf("int b=%d,size of int is %d\n", b, sizeof(b));//输出整型变量b的值和该变量所占字节数

    printf("Please input short c:");
    while (!scanf("%d", &c) || getchar() != '\n')//防止类型错误或者输入多个字符
   {
       while (getchar() != '\n');
       printf("input data error,please input another data:");
   }//要求输入短整型变量c，同时防止非法输入
    printf("short c=%d,size of short is %d\n", c, sizeof(c));//输出短整型变量c的值和该变量所占字节数

    printf("Please input float d:");
    while (!scanf("%f", &d) || getchar() != '\n')//防止类型错误或者输入多个字符
   {
       while (getchar() != '\n');
       printf("input data error,please input another data:");
   }//要求输入单精度实型变量d，同时防止非法输入
    printf("float d=%f,size of float is %d\n", d, sizeof(d));//输出单精度实型变量d的值和该变量所占字节数

    printf("Please input double e:");
    while (!scanf("%lf", &e) || getchar() != '\n')//防止类型错误或者输入多个字符
   {
       while (getchar() != '\n');
       printf("input data error,please input another data:");
   }//要求输入双精度实型变量e，同时防止非法输入
    printf("double e=%lf,size of double is %d\n", e, sizeof(e));//输出双精度实型变量e的值和该变量所占字节数

    return 0;
}
