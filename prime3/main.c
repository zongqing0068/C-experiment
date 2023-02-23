#include <stdio.h>
#include <stdlib.h>

/*线性筛法求素数*/
int main()
{
    int flag[201], prime[201], i, j, k = 1;

    for (i = 2;i <= 200;i++)
    {
        flag[i] = 1;
    }//将所有数标记为1

    for (i = 2;i <= 200;i++)
    {
        if (flag[i])
        {
            prime[k] = i;//若i没有被筛，则加入素数数组
            k++;
        }
        for (j = 1;j < k && prime[j] * i <= 200;j++)//prime[j]是一个素数
        {
            flag[prime[j] * i] = 0;
            if (!(i % prime[j]))//若i能被prime[j]整除，说明下一个prime[j]将不再是prime[j] * i的最小素因子，因此跳出循环
                break;
        }//对于每个合数，在其对应的最小素因子处将其标记为0
    }

    j = 0;

    for (i = 100;i <= 200;i++)
    {
        if(flag[i])
        {
            printf("%d ", i);
            j++;
            if (!(j % 10))
            printf("\n");
        }//输出100-200的素数，每行不超过十个

    }

    return 0;
}
