/* 文件名: Subject No.2 - program No.2
创建人: 宗晴
描述: 判断输入的三条边是否可以构成一个三角形，判断三角形的类型，输出三角形的面积 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6

/*函数名：Swap
功能：将两个数交换*/
void Swap(double *a, double *b)
{
    double tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.2 - Program No.2\n\n");//文件信息


    double a, b, c, s, p;//定义边长a,b,c,面积s,辅助计算的变量p

    printf("please input a b c:\n");
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3 || a <= EPS || b <= EPS || c <= EPS)
    {
        while (getchar() != '\n');
        printf("input data error,please input a b c:\n");
    }//输入三个正数作为三角形边长

    if(a > b) Swap(&a, &b);
    if(b > c) Swap(&b, &c);
    if(a > b) Swap(&a, &b);//将abc三个数从小到大排列

    if ((a + b - c) <= EPS)
    {
        printf("不是三角形\n");
    }//判断是否是三角形

    else
    {
        if ( fabs(a - b) <= EPS && fabs(b - c) <= EPS)
        {
            printf("等边三角形\n");
        }
        else if ((fabs(a - b) <= EPS && fabs(c * c - a * a - b * b) <= EPS))
        {
            printf("等腰直角三角形\n");
        }
        else if (fabs(a - b) <= EPS || fabs(c - b) <= EPS)
        {
            printf("等腰三角形\n");
        }
        else if (fabs(c * c - a * a - b * b) <= EPS)
        {
            printf("直角三角形\n");
        }
        else
        {
            printf("一般三角形\n");
        }//判断为何种三角形

        p = (a + b + c) / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("s = %lf", s);//计算并输出三角形面积
    }

    return 0;
}
