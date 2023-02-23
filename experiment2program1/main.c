/* 文件名: Subject No.2 - program No.1
创建人: 宗晴
描述: 分别使用宏定义和const常量定义π的值，编程计算并输出球的体积和表面积 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6
#define PI acos(-1)//宏定义pi值，特色：利用acos（-1）使得pi值更精确

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.2 - program No.1\n\n");//文件信息


    const double Pi = acos(-1);//用const定义pi值，特色：利用acos（-1）使得pi值更精确
    double r, s1, v1, s2, v2;//定义半径、表面积、体积

    printf("please input r:\n");
    while (!scanf("%lf", &r) || r <= EPS || getchar() != '\n')
    {
        while (getchar() != '\n');
        printf("input data error,please input r\n");
    }//输入一个正确的半径值，防止非法输入

    s1 = 4 * PI * r * r;
    v1 = 4.0 / 3 * PI * r * r * r;
    s2 = 4 * Pi * r * r;
    v2 = 4.0 / 3 * Pi * r * r * r;//分别用宏定义和const常量定义的pi值计算表面积和体积

    printf("用宏定义计算：s1 = %lf, v1 = %lf\n", s1, v1);
    printf("用const常量定义计算：s2 = %lf, v2 = %lf\n", s2, v2);

    return 0;
}
