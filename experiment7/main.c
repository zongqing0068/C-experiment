/* 文件名: experiment7
创建人: 宗晴
日 期: 2020.10.26.
描述：学生成绩管理系统
版本3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

void ReadScore(char cname[][N], long num[], int score[][8], int n, int t);
int Sum(int score[][8], int n, int j);
void Sum_Aver_Student(int score[][8], int n, int t);
void SelectionSort(char cname[][N], long num[], int score[][8], int n, int t, int(*compare)(int a, int b));
int Ascending(int a,int b);
int Descending(int a,int b);
void SelectionSort_Num(char cname[][N], long num[], int score[][8], int n, int t);
void SelectionSort_Name(char cname[][N], long num[], int score[][8], int n, int t);
void Percentage(int score[][8], int n, int j);

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.7\n\n");//文件信息

    int n, t, ichoice, iscore[N][8], isum, iaver, i, j, p;//n为学生人数，t为考试科目数，ichoice为用户输入的选项，iscore为学生成绩，isum为总成绩，iaver为平均成绩
    char cname[N][N], cname1[N];//cname用来存放姓名,cname1为所需查询的的学生姓名
    long lnum[N], lnumx;//lnum用来存放学号,lnumx为所需查询的的学生学号

    printf("学生成绩管理系统3.0\n\n");

    for (i = 0;; i++)
    {
        //输出菜单，读入用户的选项

        printf("1．Input record\n");
        printf("2. Calculate total and average score of every course\n");
        printf("3. Calculate total and average score of every student\n");
        printf("4. Sort in descending order by total score of every student\n");
        printf("5. Sort in ascending order by total score of every student\n");
        printf("6. Sort in ascending order by number\n");
        printf("7．Sort in dictionary order by name\n");
        printf("8．Search by number\n");
        printf("9．search by name\n");
        printf("10．Statistic analysis for every course\n");
        printf("11．List record\n");
        printf("0．Exit\n");
        printf("Please enter your choice:\n");

        while (!scanf("%d", &ichoice) || ichoice < 0 || ichoice > 11 || getchar() != '\n')//防止类型错误，或者在正确输入值后紧跟其他字符，或者输入多个字符
        {
            while (getchar() != '\n');
            printf("error\n");
        }//增加程序健壮性，根据用户的选择转入相应的操作，根据用户的选择转入相应的操作

        switch (ichoice)
        {
        case 1://录入每个学生的学号、姓名和各科考试成绩。
            printf("输入学生个数（1-30）以及考试科目数（1-6）:");
            while (scanf("%d %d", &n, &t) != 2 || n < 1 || n > 30 || t < 1 || t > 6)
            {
                while (getchar() != '\n');
                printf("error\n");
            }//增加程序健壮性
            ReadScore(cname, lnum, iscore, n, t);
            break;
        case 2://计算每门课程的总分和平均分。
            for (j = 0; j < t; j++)
            {
                isum = Sum(iscore, n, j);
                iaver = isum / n;
                printf("course%d. sum = %d, average = %d\n", j + 1, isum, iaver);
            }
            printf("\n");
            break;
        case 3://计算每个学生的总分和平均分。
            Sum_Aver_Student(iscore, n, t);
            for (j = 0; j < n; j++)
            {
                printf("%-10s: sum = %d, average = %d\n", cname[j], iscore[j][6], iscore[j][7]);
            }
            printf("\n");
            break;
        case 4://按每个学生的总分由高到低排出名次表。
            Sum_Aver_Student(iscore, n, t);
            SelectionSort(cname, lnum, iscore, n, t, Descending);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 总成绩：%-4d 名次：%-3d 各科成绩：", cname[j], lnum[j], iscore[j][6], j + 1);
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 5://按每个学生的总分由低到高排出名次表。
            Sum_Aver_Student(iscore, n, t);
            SelectionSort(cname, lnum, iscore, n, t, Ascending);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 总成绩：%-4d 名次：%-3d 各科成绩：", cname[j], lnum[j], iscore[j][6], n - j);
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 6://按学号由小到大排出成绩表。
            Sum_Aver_Student(iscore, n, t);
            SelectionSort_Num(cname, lnum, iscore, n, t);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 总成绩：%-4d 各科成绩：", cname[j], lnum[j], iscore[j][6]);
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 7://按姓名的字典顺序排出成绩表
            Sum_Aver_Student(iscore, n, t);
            SelectionSort_Name(cname, lnum, iscore, n, t);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld 总成绩：%-4d 各科成绩：", cname[j], lnum[j], iscore[j][6]);
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 8://按学号查询学生排名及其各科考试成绩。
            Sum_Aver_Student(iscore, n, t);
            printf("输入待查询学号：");
            while (!scanf("%ld", &lnumx) || getchar() != '\n')//防止类型错误，或者在正确输入值后紧跟其他字符，或者输入多个字符
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
            SelectionSort(cname, lnum, iscore, n, t, Descending);
            for (j = 0; j < n; j++)
            {
                if (lnum[j] == lnumx)
                {
                    printf("名次：%-3d 各科成绩：", j + 1);
                    for (p = 0; p < t; p++)
                        printf(" %-4d", iscore[j][p]);
                    printf("\n");
                    break;
                }
            }
            if (j == n && lnum[n - 1] != lnumx)
                printf("不存在此学号\n\n");
            printf("\n");
            break;
        case 9://按姓名查询学生排名及其各科考试成绩。
            Sum_Aver_Student(iscore, n, t);
            //getchar();
            printf("输入姓名：");
            gets(cname1);
            SelectionSort(cname, lnum, iscore, n, t, Descending);
            for (j = 0; j < n; j++)
            {
                if (strcmp(cname1, cname[j]) == 0)
                {
                    printf("名次：%-3d 各科成绩：", j + 1);
                    for (p = 0; p < t; p++)
                        printf(" %-4d", iscore[j][p]);
                    printf("\n");
                    break;
                }
            }
            if (j == n && strcmp(cname1, cname[j]) != 0)
                printf("不存在此姓名\n\n");
            break;
        case 10://按优秀（90-100分、良好（80-89分）、中等（70-79分）、及格（60 -69分）、丌及格(0-59分)5个类别，对每门课程分别统计每个类别的人数以及所占的百分比。
            for (j = 0; j < t; j++)
            {
                Percentage(iscore, n, j);
                printf("\n");
            }
            break;
        case 11://输出每个学生的学号、姓名、各科考试成绩、总分、平均分。
            Sum_Aver_Student(iscore, n, t);
            for (j = 0; j < n; j++)
            {
                printf("姓名：%-10s 学号：%-10ld", cname[j], lnum[j]);
                printf("各科成绩：");
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("sum = %d, average = %d\n", iscore[j][6], iscore[j][7]);
            }
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
输入：学生的姓名，学号和各科考试成绩，以及学生总数和考试科目数
输出：返回学生的姓名，学号和各科考试成绩
函数功能：录入学生的姓名，学号和各科考试成绩*/
void ReadScore(char cname[][N], long num[], int score[][8], int n, int t)
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        while (getchar() != '\n');
        printf("输入姓名:");
        gets(cname[i]);

        printf("输入成绩（成绩在0-100）:");
        for (j = 0; j < t; j++)
        {
            while (!scanf("%d", &score[i][j]) || score[i][j] < 0 || score[i][j] > 100)//防止类型错误或者成绩不满足要求
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
        }

        printf("输入学号（学号为正）:");
        while (!scanf("%ld", &num[i]) || num[i] <= 0)//防止类型错误或者学号不满足要求
        {
            while (getchar() != '\n');
            printf("input data error,please input another data:");
        }

        for(k = 0; k < i; k++)
        {
            if(i > 0 && num[i] == num[k])
            {
                i--;
                printf("学号已存在\n");//保证输入的学号不重
                break;
            }
        }
    }
}

/*函数名：Sum
输入：每个学生的各科考试成绩
输出：每个学生的各科总成绩
函数功能：计算n个学生各科成绩的总分*/
int Sum(int score[][8], int n, int j)
{
    int i;
    int isum = 0;
    for(i = 0; i < n; i++)
    {
        isum += score[i][j];
    }
    return isum;
}

/*函数名：Sum_Aver_Student
输入：每个学生的各科考试成绩
输出：每个学生的总成绩和平均成绩
函数功能：计算每个学生的总成绩和平均成绩，并分别存入成绩的第六列和第七列*/
void Sum_Aver_Student(int score[][8], int n, int t)
{
    int i, j;
    int isum = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < t; j++)
            isum += score[i][j];
        score[i][6] = isum;//算出总成绩存入第6列
        score[i][7] = isum / t;//算出平均成绩存入第7列
        isum = 0;
    }
}

/*函数名：SelectionSort
输入：学生的姓名，学号和各科考试成绩，以及学生总数，考试科目数，排序方法
输出：按总成绩降/升序顺序排序的学生的姓名，学号和各科考试成绩
函数功能：用选择法按总成绩降/升序顺序对cname、lnum和iscore排序*/
void SelectionSort(char cname[][N], long num[], int score[][8], int n, int t, int(*compare)(int a, int b))
{
    int i, j, k, p;
    char temp1[N];
    long temp2;
    int temp3;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(score[j][6], score[k][6]))
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
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
            /*交换成绩*/
            for (p = 0; p < 8; p++)
            {
                temp3 = score[k][p];
                score[k][p] = score[i][p];
                score[i][p] = temp3;
            }
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
输入：学生的姓名、学号和考试成绩，以及学生总数,考试科目数
输出：按学号升序顺序排序的学生的姓名、学号和考试成绩
函数功能：用选择法按学号升序顺序对cname、lnum和iscore排序*/
void SelectionSort_Num(char cname[][N], long num[], int score[][8], int n, int t)
{
    int i, j, k, p;
    char temp1[N];
    long temp2;
    int temp3;
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
            /*交换姓名*/
            strcpy(temp1, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp1);
            /*交换学号*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
            /*交换成绩*/
            for (p = 0; p < 8; p++)
            {
                temp3 = score[k][p];
                score[k][p] = score[i][p];
                score[i][p] = temp3;
            }
        }
    }
}

/*函数名：SelectionSort_Name
输入：学生的姓名、学号和考试成绩，以及学生总数,考试科目数
输出：按姓名的字典顺序排序的学生的姓名、学号和考试成绩
函数功能：用选择法按姓名的字典顺序对cname、lnum和iscore排序*/
void SelectionSort_Name(char cname[][N], long num[], int score[][8], int n, int t)
{
    int i, j, k, p;
    char temp1[N];
    long temp2;
    int temp3;
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
            strcpy(temp1, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp1);
            /*交换学号*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
            /*交换成绩*/
            for (p = 0; p < 8; p++)
            {
                temp3 = score[k][p];
                score[k][p] = score[i][p];
                score[i][p] = temp3;
            }
        }
    }
}

/*函数名：Percentage
输入：学生的各科考试成绩，学生总数以及当前的科目类别
输出：每个类别的人数以及所占的百分比
函数功能：按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格 (0—59分)5个类别，统计每个类别的人数以及所占的百分比*/
void Percentage(int score[][8], int n, int j)
{
    int inum1 = 0, inum2 = 0, inum3 = 0, inum4 = 0, inum5 = 0, i;
    for (i = 0; i < n; i++)
    {
        if (90 <= score[i][j] && score[i][j] <= 100)
            inum1++;
        else if (80 <= score[i][j] && score[i][j] <= 89)
            inum2++;
        else if (70 <= score[i][j] && score[i][j] <= 79)
            inum3++;
        else if (60 <= score[i][j] && score[i][j] <= 69)
            inum4++;
        else inum5++;
    }
    printf("课程%d:\n", j + 1);
    printf("优秀:%d %.2f%%\n", inum1, (float)inum1 / n * 100);
    printf("良好:%d %.2f%%\n", inum2, (float)inum2 / n * 100);
    printf("中等:%d %.2f%%\n", inum3, (float)inum3 / n * 100);
    printf("及格:%d %.2f%%\n", inum4, (float)inum4 / n * 100);
    printf("不及格:%d %.2f%%\n", inum5, (float)inum5 / n * 100);
}
