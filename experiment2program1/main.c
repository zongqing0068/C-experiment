/* �ļ���: Subject No.2 - program No.1
������: ����
����: �ֱ�ʹ�ú궨���const��������е�ֵ����̼��㲢����������ͱ���� */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6
#define PI acos(-1)//�궨��piֵ����ɫ������acos��-1��ʹ��piֵ����ȷ

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.2 - program No.1\n\n");//�ļ���Ϣ


    const double Pi = acos(-1);//��const����piֵ����ɫ������acos��-1��ʹ��piֵ����ȷ
    double r, s1, v1, s2, v2;//����뾶������������

    printf("please input r:\n");
    while (!scanf("%lf", &r) || r <= EPS || getchar() != '\n')
    {
        while (getchar() != '\n');
        printf("input data error,please input r\n");
    }//����һ����ȷ�İ뾶ֵ����ֹ�Ƿ�����

    s1 = 4 * PI * r * r;
    v1 = 4.0 / 3 * PI * r * r * r;
    s2 = 4 * Pi * r * r;
    v2 = 4.0 / 3 * Pi * r * r * r;//�ֱ��ú궨���const���������piֵ�������������

    printf("�ú궨����㣺s1 = %lf, v1 = %lf\n", s1, v1);
    printf("��const����������㣺s2 = %lf, v2 = %lf\n", s2, v2);

    return 0;
}
