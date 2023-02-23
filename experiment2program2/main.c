/* �ļ���: Subject No.2 - program No.2
������: ����
����: �ж�������������Ƿ���Թ���һ�������Σ��ж������ε����ͣ���������ε���� */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6

/*��������Swap
���ܣ�������������*/
void Swap(double *a, double *b)
{
    double tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.2 - Program No.2\n\n");//�ļ���Ϣ


    double a, b, c, s, p;//����߳�a,b,c,���s,��������ı���p

    printf("please input a b c:\n");
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3 || a <= EPS || b <= EPS || c <= EPS)
    {
        while (getchar() != '\n');
        printf("input data error,please input a b c:\n");
    }//��������������Ϊ�����α߳�

    if(a > b) Swap(&a, &b);
    if(b > c) Swap(&b, &c);
    if(a > b) Swap(&a, &b);//��abc��������С��������

    if ((a + b - c) <= EPS)
    {
        printf("����������\n");
    }//�ж��Ƿ���������

    else
    {
        if ( fabs(a - b) <= EPS && fabs(b - c) <= EPS)
        {
            printf("�ȱ�������\n");
        }
        else if ((fabs(a - b) <= EPS && fabs(c * c - a * a - b * b) <= EPS))
        {
            printf("����ֱ��������\n");
        }
        else if (fabs(a - b) <= EPS || fabs(c - b) <= EPS)
        {
            printf("����������\n");
        }
        else if (fabs(c * c - a * a - b * b) <= EPS)
        {
            printf("ֱ��������\n");
        }
        else
        {
            printf("һ��������\n");
        }//�ж�Ϊ����������

        p = (a + b + c) / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("s = %lf", s);//���㲢������������
    }

    return 0;
}
