/*�ļ���: Subject No.1 - program No.2
������: ����
����: ������һ��С��Ӣ���ַ�ת��Ϊ��д�ַ��󣬴�ӡͼ��*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.1 - program No.2\n\n");//�ļ���Ϣ

    char low, cap;
    int i, j, k;//�������

    printf("Input the lowercase:");
    scanf("%c", &low);
    while (low < 'a' || low  > 'z' || getchar() != '\n')
    {
        while (getchar() != '\n');
        printf("input data error,please input another data:");
        scanf(" %c", &low);
    }//����һ��СдӢ���ַ���ͬʱ��ֹ�Ƿ������Լ��������ַ�

    cap = low + 'A' - 'a';//�������СдӢ���ַ�ת���ɴ�д

    for (i = 0; i < 8; i++)
    {
       if (i & 1)//��ɫ�����˰�λ������ж���ż��
       {
           printf(" ");
       }
       for (j = 0; j < 8; j++)
       {
           printf("%c ", cap);
       }
       printf("\n");
    }//�����ӡͼ������ɫ����ӡͼ�����ֽ�ʹ�������������䣻

    return 0;
}
