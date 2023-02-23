#include <stdio.h>
#include <stdlib.h>

/*埃氏筛法求素数*/
int main()
{
    int prime[201], i, j;
    for (i = 2;i <= 200;i++)
    {
        prime[i] = 1;
    }//将所有数标记为1

    for (i = 2;i <= 200;i++)
    {
        if (prime[i])//只检查被标记为1的数
        {
            for (j = i * 2;j <= 200;j += i)
            prime[j] = 0;//将当前素数的倍数标记为0
        }
    }//将非素数标记为0

    j = 0;

    for (i = 100;i <= 200;i++)
    {
        if(prime[i])
        {
            printf("%d ", i);
            j++;
            if (!(j % 10))
            printf("\n");
        }//输出100-200的素数，每行不超过十个

    }

    return 0;
}

