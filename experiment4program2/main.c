/* �ļ���: Subject No.4 - program No.2
������: ����
����: Сѧ���˷�ѧϰϵͳ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    printf("Number:200110513\n");
    printf("Subject No.4 - Program No.2\n\n");//�ļ���Ϣ

    float right_answer, accuracy, answer;//cΪ��ȷ�𰸣�accuracyΪ��ȷ�ʣ�answerΪѧ�������
    int a, b, x, score, i;//a,bΪ������������x�����������������Լ���ӡ��䣬scoreΪ�ɼ�
    char ch;//chΪ���ɵ������

    printf("Сѧ����������ѧϰϵͳ\n\n(��10�����������⣬ÿ����Ŀֻ��һ�δ�����ᡣ\n");
    printf("10����������ɺ����ش���ȷ�ʵ���75%%����������10���⣬ֱ���ش���ȷ�ʸ���75%%Ϊֹ��\n");
    printf("���мӼ�����������������������������������С�������λ��\n\n");

    do{
        score = 0;
        for (i = 0;i < 10;i++)
        {
            srand(time(NULL));
            a = rand() % 10 + 1;
            b = rand() % 10 + 1;
            x = rand() % 4 + 1;
            switch (x)
            {
                case 1:
                    ch = '+';
                    right_answer = a + b;
                    break;
                case 2:
                    ch = '-';
                    right_answer = a - b;
                    break;
                case 3:
                    ch = '*';
                    right_answer = a * b;
                    break;
                case 4:
                    ch = '/';
                    right_answer = (float)((int)((float)a / b * 100 + 0.5)) / 100;//����������С�������λ
                    break;
            }//�������������������һ�������������ȷ�𰸴������c��

            printf("%d %c %d =?\n", a, ch, b);//��ӡ������

            while (!scanf("%f", &answer))
            {
                while(getchar() != '\n');
                printf("error\n");
            }//Ҫ��ѧ������𰸲���ֹ�Ƿ�����

            while (getchar() != '\n');//���ѧ��������𰸺��ֽ���������ķǷ��ַ�����ֹ����һ�����Ӱ��

            if (right_answer == answer)
            {
                x = rand() % 4 + 1;
                switch (x)
                {
                    case 1:
                        printf("Very good!\n");
                        break;
                    case 2:
                        printf("Excellent!\n");
                        break;
                    case 3:
                        printf("Nice work!\n");
                        break;
                    case 4:
                        printf("Keep up the good work!\n");
                        break;
                }
                score++;
            }//������ȷ���������������ľ仰�����Ҵ�Ե���Ŀ��������1

            else
            {
                x = rand() % 4 + 1;
                switch (x)
                {
                    case 1:
                        printf("No.Please try next subject.\n");
                        break;
                    case 2:
                        printf("Wrong.Be careful.\n");
                        break;
                    case 3:
                        printf("Don't give up!\n");
                        break;
                    case 4:
                        printf("Not correct.Keep trying.\n");
                        break;
                }
            }//���𰸴����������������ľ仰

        }

        accuracy = (float)score / 10 * 100;//������ȷ��
        printf("score: %d  %.2f%%\n\n", score, accuracy);//����ɼ�����ȷ��

    }while (accuracy < 75);//����ȷ�ʵ���75%��������10����

    return 0;
}
