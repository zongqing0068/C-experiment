/* �ļ���: Subject No.3 - program No.2
������: ����
����: ��������ŵ */

#include <stdio.h>
#include <stdlib.h>
#define p 1.42e8

double Number(int n);

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.3 - Program No.2\n\n");//�ļ���Ϣ

    int n;
    double number = 0, v;//����������������������

    for (n = 1;n <= 64;n++)
    {
        number += Number(n);
    }//������������

    v = number / p;//������������������

    printf("�����൱��%eƽ����\n", v);

    return 0;
}

/* ��������Number
���ܣ�����ÿ�������ӵ����� */
double Number(int n)
{
    if (n == 1)
        return 1;
    else
        return 2 * Number(n - 1);
}
