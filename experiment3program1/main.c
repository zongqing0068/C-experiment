/* �ļ���: Subject No.3 - program No.1
������: ����
����: ���100~200����������������ÿ�����10������
      �����Щ�����ķ�ת���֣�����ÿ�����10������ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Prime(int x);

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.3 - Program No.1\n\n");//�ļ���Ϣ

    int x, prime[100], i = 0, j, flag;//��������������鼰��������

    for (x = 100; x <= 200; x++)
    {
        flag = Prime(x);
        if (!flag)
        {
            i++;
            prime[i] = x;
        }
    }//��100-200��������������������

    for (j = 1; j <= i; j++)
    {
        printf("%d ", prime[j]);
        if (!(j % 10))
            printf("\n");
    }//�������е�����������ӡ����������ÿ�����10��

    printf("\n\n");

     for (j = 1; j <= i; j++)
    {
        prime[j] = prime[j] % 10 * 100 + (prime[j]-prime[j] % 10) % 100 + (prime[j] - prime[j] % 100) / 100;
        printf("%d ", prime[j]);
        if (!(j % 10))
            printf("\n");
    }//�������е�ÿ��������ת���

    return 0;
}

/*��������Prime
���ܣ��ж�����ֵ�Ƿ�Ϊ����*/
int Prime(int x)
{
    int i, flag = 0, t;
    t = (int)sqrt((double)x);
    for (i = 2; i <= t; i++)//���
    {
        if (!(x % i))
            flag += 1;
    }
    return flag;//���xΪ�������򷵻�0
}
