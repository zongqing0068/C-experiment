/* 文件名: Subject No.4 - program No.2
创建人: 宗晴
描述: 小学生乘法学习系统 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    printf("Number:200110513\n");
    printf("Subject No.4 - Program No.2\n\n");//文件信息

    float right_answer, accuracy, answer;//c为正确答案，accuracy为正确率，answer为学生输入答案
    int a, b, x, score, i;//a,b为两个操作数，x用来生成随机运算符以及打印语句，score为成绩
    char ch;//ch为生成的运算符

    printf("小学生四则运算学习系统\n\n(共10道四则运算题，每道题目只有一次答题机会。\n");
    printf("10道运算题完成后，若回答正确率低于75%%，则重新做10道题，直到回答正确率高于75%%为止。\n");
    printf("其中加减乘运算输入整数，除法运算四舍五入至小数点后两位）\n\n");

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
                    right_answer = (float)((int)((float)a / b * 100 + 0.5)) / 100;//四舍五入至小数点后两位
                    break;
            }//随机生成两个操作数和一个运算符并将正确答案存入变量c中

            printf("%d %c %d =?\n", a, ch, b);//打印运算题

            while (!scanf("%f", &answer))
            {
                while(getchar() != '\n');
                printf("error\n");
            }//要求学生输入答案并防止非法输入

            while (getchar() != '\n');//清除学生在输入答案后又紧接着输入的非法字符，防止对下一题造成影响

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
            }//若答案正确，则随机输出以上四句话，并且答对的题目数量增加1

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
            }//若答案错误，则随机输出以上四句话

        }

        accuracy = (float)score / 10 * 100;//计算正确率
        printf("score: %d  %.2f%%\n\n", score, accuracy);//输出成绩和正确率

    }while (accuracy < 75);//若正确率低于75%，则重做10道题

    return 0;
}
