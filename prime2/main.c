#include <stdio.h>
#include <stdlib.h>

/*����ɸ��������*/
int main()
{
    int prime[201], i, j;
    for (i = 2;i <= 200;i++)
    {
        prime[i] = 1;
    }//�����������Ϊ1

    for (i = 2;i <= 200;i++)
    {
        if (prime[i])//ֻ��鱻���Ϊ1����
        {
            for (j = i * 2;j <= 200;j += i)
            prime[j] = 0;//����ǰ�����ı������Ϊ0
        }
    }//�����������Ϊ0

    j = 0;

    for (i = 100;i <= 200;i++)
    {
        if(prime[i])
        {
            printf("%d ", i);
            j++;
            if (!(j % 10))
            printf("\n");
        }//���100-200��������ÿ�в�����ʮ��

    }

    return 0;
}

