/* �ļ���: Subject No.4 - program No.1
������: ����
����: Сѧ���˷�ѧϰϵͳ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.4 - program No.1\n\n");//�ļ���Ϣ


    int a, b, answer, score = 0, i, j;//a,bΪ����������
    float accuracy;

    printf("Сѧ���˷�ѧϰϵͳ��ÿ�������λ��ᣬ��10�⣬10����ȫ�����������ܷ֣�\n\n");

    for (i = 0; i < 10; i++)
    {
        srand(time(NULL));
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        printf("%d * %d =?\n", a, b);//�����������1~10֮���������������ӡ������

        for (j = 0; j < 3; j++)
        {
            while (!scanf("%d", &answer))
            {
                while(getchar() != '\n');
                printf("error\n");
            }//Ҫ��ѧ������𰸲���ֹ�Ƿ�����

            if (answer == a * b)
            {
                printf("Right!\n");
                score++;
                break;
            }//������ȷ�������"Right!"�����Ҵ�Ե���Ŀ��������1��Ȼ���������λ����ѭ��

            else if (j == 2)
            {
                printf("Wrong! Test next subject!\n");
            }//���𰸴��������λ������꣬���ӡ���������������һ��

            else
            {
                printf("Wrong! Please try again.\n");
            }//���𰸴��������λ��ỹδ���꣬���ӡ���������������һ�δ������
        }
    }

    accuracy = (float)score / 10 * 100;//������ȷ��
    printf("score: %d  %.2f%%", score, accuracy);//����ɼ�����ȷ��

    return 0;
}
