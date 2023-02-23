/* 文件名: Subject No.3 - program No.2
创建人: 宗晴
描述: 国王的许诺 */

#include <stdio.h>
#include <stdlib.h>
#define p 1.42e8

double Number(int n);

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.3 - Program No.2\n\n");//文件信息

    int n;
    double number = 0, v;//定义格数，麦子总数，体积

    for (n = 1;n <= 64;n++)
    {
        number += Number(n);
    }//计算麦子总数

    v = number / p;//将麦子总数换算成体积

    printf("麦子相当于%e平方米\n", v);

    return 0;
}

/* 函数名：Number
功能：计算每格中麦子的数量 */
double Number(int n)
{
    if (n == 1)
        return 1;
    else
        return 2 * Number(n - 1);
}
