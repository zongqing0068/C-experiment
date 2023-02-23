/* �ļ���: experiment9
������: ����
�� ��: 2020.11.14.
������ѧ���ɼ�����ϵͳ
�汾:5.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

typedef struct student
{
    char cname[10];//cname�����������
    long lnum;//lnum�������ѧ��
    int iscore[8];//iscoreΪѧ���ɼ�
} STUDENT;

void ReadScore(STUDENT stu[], int n, int t);
int Sum(STUDENT stu[], int n, int j);
void Sum_Aver_Student(STUDENT stu[], int n, int t);
void SelectionSort(STUDENT stu[], int n, int t, int(*compare)(int a, int b));
int Ascending(int a,int b);
int Descending(int a,int b);
void SelectionSort_Num(STUDENT stu[], int n, int t);
void SelectionSort_Name(STUDENT stu[], int n, int t);
void Percentage(STUDENT stu[], int n, int j);
void WritetoFile(STUDENT stu[], int n, int t);
void ReadfromFile_Print(STUDENT stu[], int *n, int *t);

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.9\n\n");//�ļ���Ϣ

    int n, t, i, j, p, ichoice, isum, iaver;//nΪѧ��������tΪ���Կ�Ŀ����isumΪ�ܳɼ���iaverΪƽ���ɼ���ichoiceΪ�û������ѡ��
    char  cname1[N];//cname1Ϊ�����ѯ�ĵ�ѧ������
    long lnumx;//lnumxΪ�����ѯ�ĵ�ѧ��ѧ��


    STUDENT stu[N];

    printf("ѧ���ɼ�����ϵͳ5.0\n\n");

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
        printf("12��Write to a file\n");
        printf("13��Read from a file\n");
        printf("0��Exit\n");
        printf("Please enter your choice:\n");

        while (scanf("%d", &ichoice) != 1 || ichoice < 0 || ichoice > 13 || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�
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
            ReadScore(stu, n, t);
            break;
        case 2://����ÿ�ſγ̵��ֺܷ�ƽ���֡�
            for (j = 0; j < t; j++)
            {
                isum = Sum(stu, n, j);
                iaver = isum / n;
                printf("course%d. sum = %d, average = %d\n", j + 1, isum, iaver);
            }
            printf("\n");
            break;
        case 3://����ÿ��ѧ�����ֺܷ�ƽ���֡�
            Sum_Aver_Student(stu, n, t);
            for (j = 0; j < n; j++)
                printf("%-10s: sum = %d, average = %d\n", stu[j].cname, stu[j].iscore[6], stu[j].iscore[7]);
            printf("\n");
            break;
        case 4://��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
            Sum_Aver_Student(stu, n, t);
            SelectionSort(stu, n, t, Descending);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ܳɼ���%-4d ���Σ�%-3d ���Ƴɼ���", stu[j].cname, stu[j].lnum, stu[j].iscore[6], j + 1);
                for (p = 0; p < t; p++)
                    printf(" %-4d", stu[j].iscore[p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 5://��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
            Sum_Aver_Student(stu, n, t);
            SelectionSort(stu, n, t, Ascending);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ܳɼ���%-4d ���Σ�%-3d ���Ƴɼ���", stu[j].cname, stu[j].lnum, stu[j].iscore[6], n - j);
                for (p = 0; p < t; p++)
                    printf(" %-4d", stu[j].iscore[p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 6://��ѧ����С�����ų��ɼ���
            Sum_Aver_Student(stu, n, t);
            SelectionSort_Num(stu, n, t);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ܳɼ���%-4d ���Ƴɼ���", stu[j].cname, stu[j].lnum, stu[j].iscore[6]);
                for (p = 0; p < t; p++)
                    printf(" %-4d", stu[j].iscore[p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 7://���������ֵ�˳���ų��ɼ���
            Sum_Aver_Student(stu, n, t);
            SelectionSort_Name(stu, n, t);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ܳɼ���%-4d ���Ƴɼ���", stu[j].cname, stu[j].lnum, stu[j].iscore[6]);
                for (p = 0; p < t; p++)
                    printf(" %-4d", stu[j].iscore[p]);
                printf("\n");
            }
            printf("\n");
            break;
        case 8://��ѧ�Ų�ѯѧ������������ƿ��Գɼ���
            Sum_Aver_Student(stu, n, t);
            SelectionSort(stu, n, t, Descending);

            printf("�������ѯѧ�ţ�");
            while (!scanf("%ld", &lnumx) || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }

            for (j = 0; j < n; j++)
            {
                if (stu[j].lnum == lnumx)
                {
                    printf("���Σ�%-3d ���Ƴɼ���", j + 1);
                    for (p = 0; p < t; p++)
                        printf(" %-4d", stu[j].iscore[p]);
                    printf("\n");
                    break;
                }
            }
            if (j == n && stu[n - 1].lnum != lnumx)
                printf("�����ڴ�ѧ��\n\n");
            printf("\n");
            break;
        case 9://��������ѯѧ������������ƿ��Գɼ���
            //getchar();
            Sum_Aver_Student(stu, n, t);
            SelectionSort(stu, n, t, Descending);

            printf("����������");
            gets(cname1);
            for (j = 0; j < n; j++)
            {
                if (strcmp(cname1, stu[j].cname) == 0)
                {
                    printf("���Σ�%-3d ���Ƴɼ���", j + 1);
                    for (p = 0; p < t; p++)
                        printf(" %-4d", stu[j].iscore[p]);
                    printf("\n");
                    break;
                }
            }
            if (j == n && strcmp(cname1, stu[j].cname) != 0)
                printf("�����ڴ�����\n\n");
            break;
        case 10://�����㣨90-100�֡����ã�80-89�֣����еȣ�70-79�֣�������60 -69�֣���آ����(0-59��)5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱȡ�
            for (j = 0; j < t; j++)
            {
                Percentage(stu, n, j);
                printf("\n");
            }
            break;
        case 11://���ÿ��ѧ����ѧ�š����������ƿ��Գɼ���
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld", stu[j].cname, stu[j].lnum);
                printf("���Ƴɼ���");
                for (p = 0; p < t; p++)
                    printf(" %-4d", stu[j].iscore[p]);
                printf("\n");
            }
            break;
        case 12://��ÿ��ѧ���ļ�¼��Ϣд���ļ���
            WritetoFile(stu, n, t);
            break;
        case 13://��ȡ�ļ���ÿ��ѧ���ļ�¼��Ϣ����ʾ��
            ReadfromFile_Print(stu, &n, &t);
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
void ReadScore(STUDENT stu[], int n, int t)
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        while (getchar() != '\n');
        printf("��������:");
        gets(stu[i].cname);//cname��������

        printf("����ɼ����ɼ���0-100��:");
        for (j = 0; j < t; j++)
        {
            while (!scanf("%d", &stu[i].iscore[j]) || stu[i].iscore[j] < 0 || stu[i].iscore[j] > 100)//��ֹ���ʹ�����߳ɼ�������Ҫ��
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
        }

        printf("����ѧ�ţ�ѧ��Ϊ����:");
        while (!scanf("%ld", &stu[i].lnum) || stu[i].lnum <= 0)//��ֹ���ʹ������ѧ�Ų�����Ҫ��
        {
            while (getchar() != '\n');
            printf("input data error,please input another data:");
        }
        for(k = 0; k < i; k++)
        {
            if(i > 0 && stu[i].lnum == stu[k].lnum)
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
int Sum(STUDENT stu[], int n, int j)
{
    int i;
    int isum = 0;
    for(i = 0; i < n; i++)
    {
        isum += stu[i].iscore[j];
    }
    return isum;
}

/*��������Sum_Aver_Student
���룺ÿ��ѧ���ĸ��ƿ��Գɼ�
�����ÿ��ѧ�����ܳɼ���ƽ���ɼ�
�������ܣ�����ÿ��ѧ�����ܳɼ���ƽ���ɼ������ֱ����ɼ��ĵ����к͵�����*/
void Sum_Aver_Student(STUDENT stu[], int n, int t)
{
    int i, j;
    int isum = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < t; j++)
            isum += stu[i].iscore[j];
        stu[i].iscore[6] = isum;//����ܳɼ������6��
        stu[i].iscore[7] = isum / t;//���ƽ���ɼ������7��
        isum = 0;
    }
}


/*��������SelectionSort
���룺ѧ����������ѧ�ź͸��ƿ��Գɼ����Լ�ѧ�����������Կ�Ŀ�������򷽷�
��������ܳɼ���/����˳�������ѧ����������ѧ�ź͸��ƿ��Գɼ�
�������ܣ���ѡ�񷨰��ܳɼ���/����˳���cname��lnum��iscore����*/
void SelectionSort(STUDENT stu[], int n, int t, int(*compare)(int a, int b))
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
            if ((*compare)(stu[j].iscore[6], stu[k].iscore[6]))
            {
                k = j;//��¼���/С���±�λ��
            }
        }
        if (k != i)//�����/С�������±�λ��
        {
            /*��������*/
            strcpy(temp1, stu[k].cname);
            strcpy(stu[k].cname, stu[i].cname);
            strcpy(stu[i].cname, temp1);
            /*����ѧ��*/
            temp2 = stu[k].lnum;
            stu[k].lnum = stu[i].lnum;
            stu[i].lnum = temp2;
            /*�����ɼ�*/
            for (p = 0; p < 8; p++)
            {
                temp3 = stu[k].iscore[p];
                stu[k].iscore[p] = stu[i].iscore[p];
                stu[i].iscore[p] = temp3;
            }
        }
    }
}

/*��������Descending
�������ܣ��жϵ�һ�������Ƿ���ڵڶ�������*/
int Descending(int a,int b)
{
    return a > b;
}

/*��������Ascending
�������ܣ��жϵ�һ�������Ƿ�С�ڵڶ�������*/
int Ascending(int a,int b)
{
    return a < b;
}

/*��������SelectionSort_Num
���룺ѧ����������ѧ�źͿ��Գɼ����Լ�ѧ������,���Կ�Ŀ��
�������ѧ������˳�������ѧ����������ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰�ѧ������˳���cname��lnum��iscore����*/
void SelectionSort_Num(STUDENT stu[], int n, int t)
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
            if (stu[j].lnum < stu[k].lnum)
            {
                k = j;//��¼��Сѧ���±�λ��
            }
        }
        if (k != i)//����Сѧ�Ų����±�λ��
        {
            /*��������*/
            strcpy(temp1, stu[k].cname);
            strcpy(stu[k].cname, stu[i].cname);
            strcpy(stu[i].cname, temp1);
            /*����ѧ��*/
            temp2 = stu[k].lnum;
            stu[k].lnum = stu[i].lnum;
            stu[i].lnum = temp2;
            /*�����ɼ�*/
            for (p = 0; p < 8; p++)
            {
                temp3 = stu[k].iscore[p];
                stu[k].iscore[p] = stu[i].iscore[p];
                stu[i].iscore[p] = temp3;
            }
        }
    }
}


/*��������SelectionSort_Name
���룺ѧ����������ѧ�źͿ��Գɼ����Լ�ѧ������,���Կ�Ŀ��
��������������ֵ�˳�������ѧ����������ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰��������ֵ�˳���cname��lnum��iscore����*/
void SelectionSort_Name(STUDENT stu[], int n, int t)
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
            if (strcmp(stu[j].cname, stu[k].cname) < 0)
            {
                k = j;//��¼��С�����±�λ��
            }
        }
        if (k != i)//����С���������±�λ��
        {
            /*��������*/
            strcpy(temp1, stu[k].cname);
            strcpy(stu[k].cname, stu[i].cname);
            strcpy(stu[i].cname, temp1);
            /*����ѧ��*/
            temp2 = stu[k].lnum;
            stu[k].lnum = stu[i].lnum;
            stu[i].lnum = temp2;
            /*�����ɼ�*/
            for (p = 0; p < 8; p++)
            {
                temp3 = stu[k].iscore[p];
                stu[k].iscore[p] = stu[i].iscore[p];
                stu[i].iscore[p] = temp3;
            }
        }
    }
}


/*��������Percentage
���룺ѧ���ĸ��ƿ��Գɼ���ѧ�������Լ���ǰ�Ŀ�Ŀ���
�����ÿ�����������Լ���ռ�İٷֱ�
�������ܣ������㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣��������� (0��59��)5�����ͳ��ÿ�����������Լ���ռ�İٷֱ�*/
void Percentage(STUDENT stu[], int n, int j)
{
    int inum1 = 0, inum2 = 0, inum3 = 0, inum4 = 0, inum5 = 0, i;
    for (i = 0; i < n; i++)
    {
        if (90 <= stu[i].iscore[j] && stu[i].iscore[j] <= 100)
            inum1++;
        else if (80 <= stu[i].iscore[j] && stu[i].iscore[j] <= 89)
            inum2++;
        else if (70 <= stu[i].iscore[j] && stu[i].iscore[j] <= 79)
            inum3++;
        else if (60 <= stu[i].iscore[j] && stu[i].iscore[j] <= 69)
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

/* ��������WritetoFile
�������ܣ���ÿ��ѧ���ļ�¼��Ϣд���ļ� */
void WritetoFile(STUDENT stu[], int n, int t)
{
    FILE *fp;
    int i, j;
    if((fp = fopen("experimen9_score.txt","w")) == NULL)
    {
        printf("Failure to open experimen9_score.txt!\n");
        exit(0);
    }
    fprintf(fp, "%d %d\n", n, t);
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%-10s%-10ld", stu[i].cname, stu[i].lnum);
        for (j = 0; j < t; j++)
            fprintf(fp, " %-4d", stu[i].iscore[j]);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

/* ��������ReadfromFile_Print
�������ܣ���ÿ��ѧ���ļ�¼��Ϣ���ļ��ж�������ӡ����Ļ�� */
void ReadfromFile_Print(STUDENT stu[], int *n, int *t)
{
    FILE *fp;
    int i, j;
    if((fp = fopen("experimen9_score.txt","r")) == NULL)
    {
        printf("Failure to open experimen9_score.txt!\n");
        exit(0);
    }
    fscanf(fp, "%d %d", n, t);
    for (i = 0; i < *n; i++)
    {
        fscanf(fp, "%10s %10ld", stu[i].cname, &stu[i].lnum);
        for (j = 0; j < *t; j++)
            fscanf(fp, " %4d", &stu[i].iscore[j]);
    }
    fclose(fp);

    for (i = 0; i < *n; i++)
    {
        printf("%-10s%-10ld", stu[i].cname, stu[i].lnum);
        for (j = 0; j < *t; j++)
            printf(" %-4d", stu[i].iscore[j]);
        printf("\n");
    }
}

