#include <stdio.h>
#include <stdlib.h>

/*����ɸ��������*/
int main()
{
    int flag[201], prime[201], i, j, k = 1;

    for (i = 2;i <= 200;i++)
    {
        flag[i] = 1;
    }//�����������Ϊ1

    for (i = 2;i <= 200;i++)
    {
        if (flag[i])
        {
            prime[k] = i;//��iû�б�ɸ���������������
            k++;
        }
        for (j = 1;j < k && prime[j] * i <= 200;j++)//prime[j]��һ������
        {
            flag[prime[j] * i] = 0;
            if (!(i % prime[j]))//��i�ܱ�prime[j]������˵����һ��prime[j]��������prime[j] * i����С�����ӣ��������ѭ��
                break;
        }//����ÿ�������������Ӧ����С�����Ӵ�������Ϊ0
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
        }//���100-200��������ÿ�в�����ʮ��

    }

    return 0;
}
