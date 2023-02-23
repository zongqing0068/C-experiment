/* 文件名: experiment6
创建人: 宗晴
日 期: 2020.10.26.
描述：学生成绩管理系统
版本：2.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

void ReadScore(char cname[][N], long lnum[], int iscore[], int n);
int Sum(int iscore[], int n);
void SelectionSort(char cname[][N], long lnum[], int iscore[], int n, int(*compare)(int a, int b));
int Ascending(int a,int b);
int Descending(int a,int b);
void SelectionSort_Num(char cname[][N], long lnum[], int iscore[], int n);
void SelectionSort_Name(char cname[][N], long lnum[], int iscore[], int n);
void Percentage(int iscore[], int n);

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.6\n\n");//文件信息

    int n, i, j, ichoice, iscore[N], isum, iaver;//n为学生人数,ichoice为用户输入的选项,iscore用来存放成绩，isum为总成绩，iaver为平均成绩
    char cname[N][N], cname1[N];//cname用来存放姓名,cname1为所需查询的的学生姓名
    long lnum[N], lnumx;//lnum用来存放学号,lnumx为所需查询的的学生学号

    printf("学生成绩管理系统2.0\n\n");

    for (i = 0;; i++)
    {
        //输出菜单，读入用户的选项
        printf("1．Input record\n");
        printf("2. Calculate total and average score of course\n");
        printf("3. Sort in descending order by score\n");
        printf("4. Sort in ascending order by score\n");
        printf("5. Sort in ascending order by number\n");
        printf("6．Search in dictionary order by number\n");
        printf("7．Search by number\n");
        printf("8．search by name\n");
        printf("9．Statistic analysis!\n");
        printf("10．List record\n");
        printf("11．Exit\n");
        printf("Please enter your choice:\n");

        while (!scanf("%d", &ichoice) || ichoice < 1 || ichoice > 11 || getchar() != '\n')//防止类型错误，或者在正确输入值后紧跟其他字符，或者输入多个字符
        {
            while (getchar() != '\n');
            printf("error\n");
        }//增加程序健壮性，根据用户的选择转入相应的操作

        switch (ichoice)
        {
        case 1://录入每个学生的姓名，学号和考试成绩
            printf("Input n（1-30）:");
            while (!scanf("%d", &n) || n < 1 || n > 30)//防止类型错误，或者输入多个字符，或者学生个数不满足要求
            {
                while (getchar() != '\n');
                printf("error\n");
            }//增加程序健壮性
            ReadScore(cname, lnum, iscore, n);
            break;
        case 2://计算课程的总分和平均分
            isum = Sum(iscore, n);
            iaver = isum / n;
            printf("sum = %d, average = %d\n\n", isum, iaver);
            break;
        case 3://按成绩由高到低排出名次表
            SelectionSort(cname, lnum, iscore, n, Descending);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 成绩：%-4d 名次：%-3d\n", cname[j], lnum[j], iscore[j], j + 1);
            }
            printf("\n");
            break;
        case 4://按成绩由低到高排出名次表
            SelectionSort(cname, lnum, iscore, n, Ascending);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 成绩：%-4d 名次：%-3d\n", cname[j], lnum[j], iscore[j], n - j);
            }
            printf("\n");
            break;
        case 5://按学号由小到大排出成绩表
            SelectionSort_Num(cname, lnum, iscore, n);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 成绩：%-4d\n", cname[j], lnum[j], iscore[j]);
            }
            printf("\n");
            break;
        case 6://按姓名的字典顺序排出成绩表
            SelectionSort_Name(cname, lnum, iscore, n);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 成绩：%-4d\n", cname[j], lnum[j], iscore[j]);
            }
            printf("\n");
            break;
        case 7://按学号查询学生排名及其考试成绩
            printf("输入学号：");
            while (!scanf("%ld", &lnumx) || getchar() != '\n')//防止类型错误，或者在正确输入值后紧跟其他字符，或者输入多个字符
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
            SelectionSort(cname, lnum, iscore, n, Descending);
            for (j = 0; j < n; j++)
            {
                if (lnum[j] == lnumx)
                {
                    printf("名次：%-3d 成绩：%-4d\n\n", j + 1, iscore[j]);
                    break;
                }
            }
            if (j == n && lnum[n - 1] != lnumx)
                printf("不存在此学号\n\n");
            break;
        case 8://按姓名查询学生排名及其考试成绩
            printf("输入姓名：");
            gets(cname1);
            SelectionSort(cname, lnum, iscore, n, Descending);
            for (j = 0; j < n; j++)
            {
                if (strcmp(cname1, cname[j]) == 0)
                {
                    printf("名次：%-3d 成绩：%-4d\n\n", j + 1, iscore[j]);
                    break;
                }
            }
            if (j == n && strcmp(cname1, cname[j]) != 0)
                printf("不存在此姓名\n\n");
            break;
        case 9://按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格 (0—59分)5个类别，统计每个类别的人数以及所占的百分比
            Percentage(iscore, n);
            printf("\n");
            break;
        case 10://输出每个学生的学号、姓名、考试成绩以及课程总分和平均分
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 成绩：%-4d\n", cname[j], lnum[j], iscore[j]);
            }
            isum = Sum(iscore, n);
            iaver = isum / n;
            printf("sum = %d, average = %d\n\n", isum, iaver);
            break;
        case 11://退出
            goto end;

        }
    }
end:
    ;

    return 0;
}

/*函数名：ReadScore
输入：学生的姓名，学号和考试成绩，以及学生总数
输出：返回学生的姓名，学号和考试成绩
函数功能：录入学生的姓名，学号和考试成绩*/
void ReadScore(char cname[][N], long lnum[], int iscore[], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        while (getchar() != '\n');
        printf("输入姓名:");
        gets(cname[i]);

        printf("输入学号和成绩（学号为正，成绩在0-100）:");
        while (scanf("%ld %d", &lnum[i], &iscore[i]) != 2 || lnum[i] <= 0 || iscore[i] < 0 || iscore[i] > 100)//防止类型错误或者输入多个字符或者学号以及成绩不满足要求
        {
            while (getchar() != '\n');
            printf("input data error,please input another data:");
        }
        for(j = 0; j < i; j++)
        {
            if(i > 0 && lnum[i] == lnum[j])
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
int Sum(int iscore[], int n)
{
    int i;
    int isum = 0;
    for(i = 0; i < n; i++)
    {
        isum += iscore[i];
    }
    return isum;
}

/*函数名：SelectionSort
输入：学生的姓名，学号和考试成绩，以及学生总数，排序方法
输出：按成绩降/升序顺序排序的学生的姓名，学号和考试成绩
函数功能：用选择法按成绩降/升序顺序对cname和ltable排序*/
void SelectionSort(char cname[][N], long lnum[], int iscore[], int n, int(*compare)(int a, int b))
{
    int i, j, k, temp3;
    char temp1[N];
    long temp2;

    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(iscore[j], iscore[k]))
            {
                k = j;//记录最大/小数下标位置
            }
        }
        if (k != i)//若最大/小数不在下标位置
        {
            /*交换姓名*/
            strcpy(temp1, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp1);
            /*交换学号*/
            temp2 = lnum[k];
            lnum[k] = lnum[i];
            lnum[i] = temp2;
            /*交换成绩*/
            temp3 = iscore[k];
            iscore[k] = iscore[i];
            iscore[i] = temp3;
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
输入：学生的姓名、学号和考试成绩，以及学生总数
输出：按学号升序顺序排序的学生的姓名、学号和考试成绩
函数功能：用选择法按学号升序顺序对cname和ltable排序*/
void SelectionSort_Num(char cname[][N], long lnum[], int iscore[], int n)
{
    int i, j, k, temp2;
    char temp[N];
    long temp1;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (lnum[j] < lnum[k])
            {
                k = j;//记录最小学号下标位置
            }
        }
        if (k != i)//若最小学号不在下标位置
        {
            /*交换姓名*/
            strcpy(temp, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp);
            /*交换学号*/
            temp1 = lnum[k];
            lnum[k] = lnum[i];
            lnum[i] = temp1;
            /*交换成绩*/
            temp2 = iscore[k];
            iscore[k] = iscore[i];
            iscore[i] = temp2;
        }
    }
}

/*函数名：SelectionSort_Name
输入：学生的姓名、学号和考试成绩，以及学生总数
输出：按姓名的字典顺序排序的学生的姓名、学号和考试成绩
函数功能：用选择法按姓名的字典顺序对cname和ltable排序*/
void SelectionSort_Name(char cname[][N], long lnum[], int iscore[], int n)
{
    int i, j, k, temp2;
    char temp[N];
    long temp1;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(cname[j], cname[k]) < 0)
            {
                k = j;//记录最小姓名下标位置
            }
        }
        if (k != i)//若最小姓名不在下标位置
        {
            /*交换姓名*/
            strcpy(temp, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp);
            /*交换学号*/
            temp1 = lnum[k];
            lnum[k] = lnum[i];
            lnum[i] = temp1;
            /*交换成绩*/
            temp2 = iscore[k];
            iscore[k] = iscore[i];
            iscore[i] = temp2;
        }
    }
}

/*函数名：Percentage
输入：学生的学号和考试成绩，以及学生总数
输出：每个类别的人数以及所占的百分比
函数功能：按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格 (0—59分)5个类别，统计每个类别的人数以及所占的百分比*/
void Percentage(int iscore[], int n)
{
    int inum1 = 0, inum2 = 0, inum3 = 0, inum4 = 0, inum5 = 0, i;
    for (i = 0; i < n; i++)
    {
        if (90 <= iscore[i] && iscore[i] <= 100)
            inum1++;
        else if (80 <= iscore[i] && iscore[i] <= 89)
            inum2++;
        else if (70 <= iscore[i] && iscore[i] <= 79)
            inum3++;
        else if (60 <= iscore[i] && iscore[i] <= 69)
            inum4++;
        else inum5++;
    }
    printf("优秀:%d %.2f%%\n", inum1, (float)inum1 / n * 100);
    printf("良好:%d %.2f%%\n", inum2, (float)inum2 / n * 100);
    printf("中等:%d %.2f%%\n", inum3, (float)inum3 / n * 100);
    printf("及格:%d %.2f%%\n", inum4, (float)inum4 / n * 100);
    printf("不及格:%d %.2f%%\n", inum5, (float)inum5 / n * 100);
}
