/* 文件名: experiment5
创建人: 宗晴
日 期: 2020.10.26.
描述：学生成绩管理系统
版本：1.0
*/

#include <stdio.h>
#include <stdlib.h>
#define N 30

void ReadScore(int score[], long num[], int n);
int Sum(int score[], int n);
void SelectionSort(int score[], long num[], int n, int(*compare)(int a, int b));
void SelectionSort_Num(int score[], long num[], int n);
void Percentage(int score[], long num[], int n);
int Ascending(int a,int b);
int Descending(int a,int b);

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.5\n\n");//文件信息

    int ichoice, score[N], isum, iaver, n, i, j;//ichoice为用户输入的选项，score[N]为学生成绩，isum为总成绩，iaver为平均成绩, n为总人数
    long num[N], lnum;//num[N]为学生学号, lnum为所需查询的的学生学号

    printf("学生成绩管理系统1.0\n\n");

    for (i = 0;; i++)
    {
        //输出菜单，读入用户的选项
        printf("1．Input record\n");
        printf("2. Calculate total and average score of course\n");
        printf("3. Sort in descending order by score\n");
        printf("4. Sort in ascending order by score\n");
        printf("5. Sort in ascending order by number\n");
        printf("6．Search by number\n");
        printf("7．Statistic analysis\n");
        printf("8．List record\n");
        printf("0．Exit\n");
        printf("Please enter your choice:\n");

        while (!scanf("%d", &ichoice) || ichoice < 0 || ichoice > 8 || getchar() != '\n')//防止类型错误，或者在正确输入值后紧跟其他字符，或者输入多个字符
        {
            while (getchar() != '\n');
            printf("error\n");
        }//增加程序健壮性，根据用户的选择转入相应的操作

        switch (ichoice)
        {
        case 1://录入每个学生的学号和考试成绩
            printf("输入学生个数（1-30）：");
            while (!scanf("%d", &n) || n < 1 || n > 30 || getchar() != '\n')//防止类型错误，或者在正确输入值后紧跟其他字符，或者输入多个字符，或者学生个数不满足要求
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
            ReadScore(score, num, n);
            break;
        case 2://计算课程的总分和平均分
            isum = Sum(score, n);
            iaver = isum / n;
            printf("sum = %d, average = %d\n\n", isum, iaver);
            break;
        case 3://按成绩由高到低排出名次表
            SelectionSort(score, num, n, Descending);
            for (j = 0; j < n; j++)
            {
                printf("学号：%10ld 成绩：%4d 名次：%3d\n", num[j], score[j], j + 1);
            }
            printf("\n");
            break;
        case 4://按成绩由低到高排出名次表
            SelectionSort(score, num, n, Ascending);
            for (j = 0; j < n; j++)
            {
                printf("学号：%10ld 成绩：%4d 名次：%3d\n", num[j], score[j], n - j);
            }
            printf("\n");
            break;
        case 5://按学号由小到大排出成绩表
            SelectionSort_Num(score, num, n);
            for (j = 0; j < n; j++)
            {
                printf("学号：%10ld 成绩：%4d\n", num[j], score[j]);
            }
            printf("\n");
            break;
        case 6://按学号查询学生排名及其考试成绩
            printf("输入待查询学号：");
            while (!scanf("%ld", &lnum) || getchar() != '\n')//防止类型错误，或者在正确输入值后紧跟其他字符，或者输入多个字符
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
            SelectionSort(score, num, n, Descending);
            for (j = 0; j < n; j++)
            {
                if (num[j] == lnum)
                {
                    printf("名次：%3d 成绩：%4d\n\n", j + 1, score[j]);
                    break;
                }
            }
            if (j == n && num[n - 1] != lnum)
                printf("不存在此学号\n\n");
            break;
        case 7://按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格 (0—59分)5个类别，统计每个类别的人数以及所占的百分比
            Percentage(score, num, n);
            printf("\n");
            break;
        case 8://输出每个学生的学号、考试成绩以及课程总分和平均分
            for (j = 0; j < n; j++)
            {
                printf("学号：%10ld 成绩：%4d\n", num[j], score[j]);
            }
            isum = Sum(score, n);
            iaver = isum / n;
            printf("sum = %d, average = %d\n\n", isum, iaver);
            break;
        case 0://退出
            goto end;

        }
    }
end:
    ;


    return 0;
}

/*函数名：ReadScore
输入：学生的个数，学号和考试成绩
输出：返回学生的学号和考试成绩
函数功能：录入学生的学号和考试成绩*/
void ReadScore(int score[], long num[], int n)
{
    int i, j;//保证进入循环后数组下标从0开始

    for (i = 0; i < n; i++)
    {
        printf("输入学号和成绩（均不可小于0）:");
        while (scanf("%ld %d", &num[i], &score[i]) != 2 || num[i] <= 0 || score[i] < 0 || score[i] > 100|| getchar() != '\n')//防止类型错误或者输入多个字符或者学号以及成绩不满足要求
        {
            while (getchar() != '\n');
            printf("input data error,please input another data:");
        }
        for(j = 0; j < i; j++)
        {
            if(i > 0 && num[i] == num[j])
            {
                i--;
                printf("学号已存在\n");//保证输入的学号不重
                break;
            }
        }
    }
}

/*函数名：Sum
输入：学生的考试成绩
输出：学生的总成绩
函数功能：计算n个学生成绩的总分*/
int Sum(int score[], int n)
{
    int i, isum = 0;
    for(i = 0; i < n; i++)
    {
        isum += score[i];
    }
    return isum;
}

/*函数名：SelectionSort
输入：学生的学号和考试成绩，以及学生总数，排序方法
输出：按成绩降/升序顺序排序的学生的学号和考试成绩
函数功能：用选择法按score数组元素降/升序顺序对score和num排序*/
void SelectionSort(int score[], long num[], int n, int(*compare)(int a, int b))
{
    int i, j, k, temp1;
    long temp2;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(score[j], score[k]))
            {
                k = j;//记录最大/小数下标位置
            }
        }
        if (k != i)//若最大/小数不在下标位置
        {
            /*交换成绩*/
            temp1 = score[k];
            score[k] = score[i];
            score[i] = temp1;
            /*交换学号*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
        }
    }
}

/*函数名：Descending
函数功能：使数据按降序排序*/
int Descending(int a,int b)
{
    return a > b;
}

/*函数名：Ascending
函数功能：使数据按升序排序*/
int Ascending(int a,int b)
{
    return a < b;
}

/*函数名：SelectionSort_Num
输入：学生的学号和考试成绩，以及学生总数
输出：按学号升序顺序排序的学生的学号和考试成绩
函数功能：用选择法按num数组元素升序顺序对score和num排序*/
void SelectionSort_Num(int score[], long num[], int n)
{
    int i, j, k, temp1;
    long temp2;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (num[j] < num[k])
            {
                k = j;//记录最小学号下标位置
            }
        }
        if (k != i)//若最小学号不在下标位置
        {
            /*交换成绩*/
            temp1 = score[k];
            score[k] = score[i];
            score[i] = temp1;
            /*交换学号*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
        }
    }
}

/*函数名：Percentage
输入：学生的学号和考试成绩，以及学生总数
输出：每个类别的人数以及所占的百分比
函数功能：按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格 (0—59分)5个类别，统计每个类别的人数以及所占的百分比*/
void Percentage(int score[], long num[], int n)
{
    int inum1 = 0, inum2 = 0, inum3 = 0, inum4 = 0, inum5 = 0, i;
    for (i = 0; i < n; i++)
    {
        if (90 <= score[i] && score[i] <= 100)
            inum1++;
        else if (80 <= score[i] && score[i] <= 89)
            inum2++;
        else if (70 <= score[i] && score[i] <= 79)
            inum3++;
        else if (60 <= score[i] && score[i] <= 69)
            inum4++;
        else inum5++;
    }
    printf("优秀:%d %.2f%%\n", inum1, (float)inum1 / n * 100);
    printf("良好:%d %.2f%%\n", inum2, (float)inum2 / n * 100);
    printf("中等:%d %.2f%%\n", inum3, (float)inum3 / n * 100);
    printf("及格:%d %.2f%%\n", inum4, (float)inum4 / n * 100);
    printf("不及格:%d %.2f%%\n", inum5, (float)inum5 / n * 100);

}
