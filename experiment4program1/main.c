/* 文件名: Subject No.4 - program No.1
创建人: 宗晴
描述: 小学生乘法学习系统 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.4 - program No.1\n\n");//文件信息


    int a, b, answer, score = 0, i, j;//a,b为两个操作数
    float accuracy;

    printf("小学生乘法学习系统（每题有三次机会，共10题，10道题全部做完后，输出总分）\n\n");

    for (i = 0; i < 10; i++)
    {
        srand(time(NULL));
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        printf("%d * %d =?\n", a, b);//随机产生两个1~10之间的正整数，并打印出问题

        for (j = 0; j < 3; j++)
        {
            while (!scanf("%d", &answer))
            {
                while(getchar() != '\n');
                printf("error\n");
            }//要求学生输入答案并防止非法输入

            if (answer == a * b)
            {
                printf("Right!\n");
                score++;
                break;
            }//若答案正确，则输出"Right!"，并且答对的题目数量增加1，然后跳出三次机会的循环

            else if (j == 2)
            {
                printf("Wrong! Test next subject!\n");
            }//若答案错误且三次机会用完，则打印出上述语句后进入下一题

            else
            {
                printf("Wrong! Please try again.\n");
            }//若答案错误且三次机会还未用完，则打印出上述语句后继续下一次答题机会
        }
    }

    accuracy = (float)score / 10 * 100;//计算正确率
    printf("score: %d  %.2f%%", score, accuracy);//输出成绩和正确率

    return 0;
}
