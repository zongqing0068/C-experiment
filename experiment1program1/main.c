/* �ļ���: Subject No.1 - program No.1
������: ����
����: ������ֱ�����ֵ�͸ñ�����ռ�ֽ��� */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.1 - Program No.1\n\n");//�ļ���Ϣ


    char a;
    int b;
    short int c;
    float d;
    double e;//���������ͬ���͵ı���


    printf("Please input char a:");
    while (!scanf("%c", &a) || getchar() != '\n')//��ֹ���ʹ�������������ַ�
    {
        while (getchar() != '\n');
        printf("input data error,please input another data:");
    }//Ҫ�������ַ��ͱ���a��ͬʱ��ֹ�Ƿ�����
    printf("char a=%c,size of char is %d\n", a, sizeof(a));//����ַ��ͱ���a��ֵ�͸ñ�����ռ�ֽ���

    printf("Please input int b:");
    while (!scanf("%d", &b) || getchar() != '\n')//��ֹ���ʹ�������������ַ�
   {
       while (getchar() != '\n');
       printf("input data error,please input another data:");
   }//Ҫ���������ͱ���b��ͬʱ��ֹ�Ƿ�����
    printf("int b=%d,size of int is %d\n", b, sizeof(b));//������ͱ���b��ֵ�͸ñ�����ռ�ֽ���

    printf("Please input short c:");
    while (!scanf("%d", &c) || getchar() != '\n')//��ֹ���ʹ�������������ַ�
   {
       while (getchar() != '\n');
       printf("input data error,please input another data:");
   }//Ҫ����������ͱ���c��ͬʱ��ֹ�Ƿ�����
    printf("short c=%d,size of short is %d\n", c, sizeof(c));//��������ͱ���c��ֵ�͸ñ�����ռ�ֽ���

    printf("Please input float d:");
    while (!scanf("%f", &d) || getchar() != '\n')//��ֹ���ʹ�������������ַ�
   {
       while (getchar() != '\n');
       printf("input data error,please input another data:");
   }//Ҫ�����뵥����ʵ�ͱ���d��ͬʱ��ֹ�Ƿ�����
    printf("float d=%f,size of float is %d\n", d, sizeof(d));//���������ʵ�ͱ���d��ֵ�͸ñ�����ռ�ֽ���

    printf("Please input double e:");
    while (!scanf("%lf", &e) || getchar() != '\n')//��ֹ���ʹ�������������ַ�
   {
       while (getchar() != '\n');
       printf("input data error,please input another data:");
   }//Ҫ������˫����ʵ�ͱ���e��ͬʱ��ֹ�Ƿ�����
    printf("double e=%lf,size of double is %d\n", e, sizeof(e));//���˫����ʵ�ͱ���e��ֵ�͸ñ�����ռ�ֽ���

    return 0;
}
