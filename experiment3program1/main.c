/* 文件名: Subject No.3 - program No.1
创建人: 宗晴
描述: 输出100~200的所有素数，限制每行输出10个数字
      输出这些素数的反转数字，限制每行输出10个数字 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Prime(int x);

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.3 - Program No.1\n\n");//文件信息

    int x, prime[100], i = 0, j, flag;//定义存素数的数组及其它变量

    for (x = 100; x <= 200; x++)
    {
        flag = Prime(x);
        if (!flag)
        {
            i++;
            prime[i] = x;
        }
    }//将100-200的所有素数存入数组中

    for (j = 1; j <= i; j++)
    {
        printf("%d ", prime[j]);
        if (!(j % 10))
            printf("\n");
    }//将数组中的所有素数打印出来，限制每行输出10个

    printf("\n\n");

     for (j = 1; j <= i; j++)
    {
        prime[j] = prime[j] % 10 * 100 + (prime[j]-prime[j] % 10) % 100 + (prime[j] - prime[j] % 100) / 100;
        printf("%d ", prime[j]);
        if (!(j % 10))
            printf("\n");
    }//将数组中的每个素数反转输出

    return 0;
}

/*函数名：Prime
功能：判断输入值是否为素数*/
int Prime(int x)
{
    int i, flag = 0, t;
    t = (int)sqrt((double)x);
    for (i = 2; i <= t; i++)//穷举
    {
        if (!(x % i))
            flag += 1;
    }
    return flag;//如果x为素数，则返回0
}
