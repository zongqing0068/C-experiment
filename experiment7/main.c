/* �ļ���: experiment7
������: ����
�� ��: 2020.10.26.
������ѧ���ɼ�����ϵͳ
�汾3.0
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
    printf("Subject No.7\n\n");//�ļ���Ϣ

    int n, t, ichoice, iscore[N][8], isum, iaver, i, j, p;//nΪѧ��������tΪ���Կ�Ŀ����ichoiceΪ�û������ѡ�iscoreΪѧ���ɼ���isumΪ�ܳɼ���iaverΪƽ���ɼ�
    char cname[N][N], cname1[N];//cname�����������,cname1Ϊ�����ѯ�ĵ�ѧ������
    long lnum[N], lnumx;//lnum�������ѧ��,lnumxΪ�����ѯ�ĵ�ѧ��ѧ��

    printf("ѧ���ɼ�����ϵͳ3.0\n\n");

    for (i = 0;; i++)
    {
        //����˵��������û���ѡ��

        printf("1��Input record\n");
        printf("2. Calculate total and average score of every course\n");
        printf("3. Calculate total and average score of every student\n");
        printf("4. Sort in descending order by total score of every student\n");
        printf("5. Sort in ascending order by total score of every student\n");
        printf("6. Sort in ascending order by number\n");
        printf("7��Sort in dictionary order by name\n");
        printf("8��Search by number\n");
        printf("9��search by name\n");
        printf("10��Statistic analysis for every course\n");
        printf("11��List record\n");
        printf("0��Exit\n");
        printf("Please enter your choice:\n");

        while (!scanf("%d", &ichoice) || ichoice < 0 || ichoice > 11 || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�
        {
            while (getchar() != '\n');
            printf("error\n");
        }//���ӳ���׳�ԣ������û���ѡ��ת����Ӧ�Ĳ����������û���ѡ��ת����Ӧ�Ĳ���

        switch (ichoice)
        {
        case 1://¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ���
            printf("����ѧ��������1-30���Լ����Կ�Ŀ����1-6��:");
            while (scanf("%d %d", &n, &t) != 2 || n < 1 || n > 30 || t < 1 || t > 6)
            {
                while (getchar() != '\n');
                printf("error\n");
            }//���ӳ���׳��
            ReadScore(cname, lnum, iscore, n, t);
            break;
        case 2://����ÿ�ſγ̵��ֺܷ�ƽ���֡�
            for (j = 0; j < t; j++)
            {
                isum = Sum(iscore, n, j);
                iaver = isum / n;
                printf("course%d. sum = %d, average = %d\n", j + 1, isum, iaver);
            }
            printf("\n");
            break;
        case 3://����ÿ��ѧ�����ֺܷ�ƽ���֡�
            Sum_Aver_Student(iscore, n, t);
            for (j = 0; j < n; j++)
            {
                printf("%-10s: sum = %d, average = %d\n", cname[j], iscore[j][6], iscore[j][7]);
            }
            printf("\n");
            break;
        case 4://��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
            Sum_Aver_Student(iscore, n, t);
            SelectionSort(cname, lnum, iscore, n, t, Descending);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ܳɼ���%-4d ���Σ�%-3d ���Ƴɼ���", cname[j], lnum[j], iscore[j][6], j + 1);
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 5://��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
            Sum_Aver_Student(iscore, n, t);
            SelectionSort(cname, lnum, iscore, n, t, Ascending);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ܳɼ���%-4d ���Σ�%-3d ���Ƴɼ���", cname[j], lnum[j], iscore[j][6], n - j);
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 6://��ѧ����С�����ų��ɼ���
            Sum_Aver_Student(iscore, n, t);
            SelectionSort_Num(cname, lnum, iscore, n, t);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ܳɼ���%-4d ���Ƴɼ���", cname[j], lnum[j], iscore[j][6]);
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 7://���������ֵ�˳���ų��ɼ���
            Sum_Aver_Student(iscore, n, t);
            SelectionSort_Name(cname, lnum, iscore, n, t);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ܳɼ���%-4d ���Ƴɼ���", cname[j], lnum[j], iscore[j][6]);
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 8://��ѧ�Ų�ѯѧ������������ƿ��Գɼ���
            Sum_Aver_Student(iscore, n, t);
            printf("�������ѯѧ�ţ�");
            while (!scanf("%ld", &lnumx) || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
            SelectionSort(cname, lnum, iscore, n, t, Descending);
            for (j = 0; j < n; j++)
            {
                if (lnum[j] == lnumx)
                {
                    printf("���Σ�%-3d ���Ƴɼ���", j + 1);
                    for (p = 0; p < t; p++)
                        printf(" %-4d", iscore[j][p]);
                    printf("\n");
                    break;
                }
            }
            if (j == n && lnum[n - 1] != lnumx)
                printf("�����ڴ�ѧ��\n\n");
            printf("\n");
            break;
        case 9://��������ѯѧ������������ƿ��Գɼ���
            Sum_Aver_Student(iscore, n, t);
            //getchar();
            printf("����������");
            gets(cname1);
            SelectionSort(cname, lnum, iscore, n, t, Descending);
            for (j = 0; j < n; j++)
            {
                if (strcmp(cname1, cname[j]) == 0)
                {
                    printf("���Σ�%-3d ���Ƴɼ���", j + 1);
                    for (p = 0; p < t; p++)
                        printf(" %-4d", iscore[j][p]);
                    printf("\n");
                    break;
                }
            }
            if (j == n && strcmp(cname1, cname[j]) != 0)
                printf("�����ڴ�����\n\n");
            break;
        case 10://�����㣨90-100�֡����ã�80-89�֣����еȣ�70-79�֣�������60 -69�֣���آ����(0-59��)5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱȡ�
            for (j = 0; j < t; j++)
            {
                Percentage(iscore, n, j);
                printf("\n");
            }
            break;
        case 11://���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֡�ƽ���֡�
            Sum_Aver_Student(iscore, n, t);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld", cname[j], lnum[j]);
                printf("���Ƴɼ���");
                for (p = 0; p < t; p++)
                    printf(" %-4d", iscore[j][p]);
                printf("sum = %d, average = %d\n", iscore[j][6], iscore[j][7]);
            }
            break;
        case 0://�˳�
            goto end;

        }
    }
end:
    ;

    return 0;
}

/*��������ReadScore
���룺ѧ����������ѧ�ź͸��ƿ��Գɼ����Լ�ѧ�������Ϳ��Կ�Ŀ��
���������ѧ����������ѧ�ź͸��ƿ��Գɼ�
�������ܣ�¼��ѧ����������ѧ�ź͸��ƿ��Գɼ�*/
void ReadScore(char cname[][N], long num[], int score[][8], int n, int t)
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        while (getchar() != '\n');
        printf("��������:");
        gets(cname[i]);

        printf("����ɼ����ɼ���0-100��:");
        for (j = 0; j < t; j++)
        {
            while (!scanf("%d", &score[i][j]) || score[i][j] < 0 || score[i][j] > 100)//��ֹ���ʹ�����߳ɼ�������Ҫ��
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
        }

        printf("����ѧ�ţ�ѧ��Ϊ����:");
        while (!scanf("%ld", &num[i]) || num[i] <= 0)//��ֹ���ʹ������ѧ�Ų�����Ҫ��
        {
            while (getchar() != '\n');
            printf("input data error,please input another data:");
        }

        for(k = 0; k < i; k++)
        {
            if(i > 0 && num[i] == num[k])
            {
                i--;
                printf("ѧ���Ѵ���\n");//��֤�����ѧ�Ų���
                break;
            }
        }
    }
}

/*��������Sum
���룺ÿ��ѧ���ĸ��ƿ��Գɼ�
�����ÿ��ѧ���ĸ����ܳɼ�
�������ܣ�����n��ѧ�����Ƴɼ����ܷ�*/
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

/*��������Sum_Aver_Student
���룺ÿ��ѧ���ĸ��ƿ��Գɼ�
�����ÿ��ѧ�����ܳɼ���ƽ���ɼ�
�������ܣ�����ÿ��ѧ�����ܳɼ���ƽ���ɼ������ֱ����ɼ��ĵ����к͵�����*/
void Sum_Aver_Student(int score[][8], int n, int t)
{
    int i, j;
    int isum = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < t; j++)
            isum += score[i][j];
        score[i][6] = isum;//����ܳɼ������6��
        score[i][7] = isum / t;//���ƽ���ɼ������7��
        isum = 0;
    }
}

/*��������SelectionSort
���룺ѧ����������ѧ�ź͸��ƿ��Գɼ����Լ�ѧ�����������Կ�Ŀ�������򷽷�
��������ܳɼ���/����˳�������ѧ����������ѧ�ź͸��ƿ��Գɼ�
�������ܣ���ѡ�񷨰��ܳɼ���/����˳���cname��lnum��iscore����*/
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
                k = j;//��¼���/С���±�λ��
            }
        }
        if (k != i)//�����/С�������±�λ��
        {
            /*��������*/
            strcpy(temp1, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp1);
            /*����ѧ��*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
            /*�����ɼ�*/
            for (p = 0; p < 8; p++)
            {
                temp3 = score[k][p];
                score[k][p] = score[i][p];
                score[i][p] = temp3;
            }
        }
    }
}

/*��������Descending
�������ܣ�ʹ���ݰ���������*/
int Descending(int a,int b)
{
    return a > b;
}

/*��������Ascending
�������ܣ�ʹ���ݰ���������*/
int Ascending(int a,int b)
{
    return a < b;
}

/*��������SelectionSort_Num
���룺ѧ����������ѧ�źͿ��Գɼ����Լ�ѧ������,���Կ�Ŀ��
�������ѧ������˳�������ѧ����������ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰�ѧ������˳���cname��lnum��iscore����*/
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
                k = j;//��¼��Сѧ���±�λ��
            }
        }
        if (k != i)//����Сѧ�Ų����±�λ��
        {
            /*��������*/
            strcpy(temp1, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp1);
            /*����ѧ��*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
            /*�����ɼ�*/
            for (p = 0; p < 8; p++)
            {
                temp3 = score[k][p];
                score[k][p] = score[i][p];
                score[i][p] = temp3;
            }
        }
    }
}

/*��������SelectionSort_Name
���룺ѧ����������ѧ�źͿ��Գɼ����Լ�ѧ������,���Կ�Ŀ��
��������������ֵ�˳�������ѧ����������ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰��������ֵ�˳���cname��lnum��iscore����*/
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
                k = j;//��¼��С�����±�λ��
            }
        }
        if (k != i)//����С���������±�λ��
        {
            /*��������*/
            strcpy(temp1, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp1);
            /*����ѧ��*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
            /*�����ɼ�*/
            for (p = 0; p < 8; p++)
            {
                temp3 = score[k][p];
                score[k][p] = score[i][p];
                score[i][p] = temp3;
            }
        }
    }
}

/*��������Percentage
���룺ѧ���ĸ��ƿ��Գɼ���ѧ�������Լ���ǰ�Ŀ�Ŀ���
�����ÿ�����������Լ���ռ�İٷֱ�
�������ܣ������㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣��������� (0��59��)5�����ͳ��ÿ�����������Լ���ռ�İٷֱ�*/
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
    printf("�γ�%d:\n", j + 1);
    printf("����:%d %.2f%%\n", inum1, (float)inum1 / n * 100);
    printf("����:%d %.2f%%\n", inum2, (float)inum2 / n * 100);
    printf("�е�:%d %.2f%%\n", inum3, (float)inum3 / n * 100);
    printf("����:%d %.2f%%\n", inum4, (float)inum4 / n * 100);
    printf("������:%d %.2f%%\n", inum5, (float)inum5 / n * 100);
}
