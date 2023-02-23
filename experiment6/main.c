/* �ļ���: experiment6
������: ����
�� ��: 2020.10.26.
������ѧ���ɼ�����ϵͳ
�汾��2.0
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
    printf("Subject No.6\n\n");//�ļ���Ϣ

    int n, i, j, ichoice, iscore[N], isum, iaver;//nΪѧ������,ichoiceΪ�û������ѡ��,iscore������ųɼ���isumΪ�ܳɼ���iaverΪƽ���ɼ�
    char cname[N][N], cname1[N];//cname�����������,cname1Ϊ�����ѯ�ĵ�ѧ������
    long lnum[N], lnumx;//lnum�������ѧ��,lnumxΪ�����ѯ�ĵ�ѧ��ѧ��

    printf("ѧ���ɼ�����ϵͳ2.0\n\n");

    for (i = 0;; i++)
    {
        //����˵��������û���ѡ��
        printf("1��Input record\n");
        printf("2. Calculate total and average score of course\n");
        printf("3. Sort in descending order by score\n");
        printf("4. Sort in ascending order by score\n");
        printf("5. Sort in ascending order by number\n");
        printf("6��Search in dictionary order by number\n");
        printf("7��Search by number\n");
        printf("8��search by name\n");
        printf("9��Statistic analysis!\n");
        printf("10��List record\n");
        printf("11��Exit\n");
        printf("Please enter your choice:\n");

        while (!scanf("%d", &ichoice) || ichoice < 1 || ichoice > 11 || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�
        {
            while (getchar() != '\n');
            printf("error\n");
        }//���ӳ���׳�ԣ������û���ѡ��ת����Ӧ�Ĳ���

        switch (ichoice)
        {
        case 1://¼��ÿ��ѧ����������ѧ�źͿ��Գɼ�
            printf("Input n��1-30��:");
            while (!scanf("%d", &n) || n < 1 || n > 30)//��ֹ���ʹ��󣬻����������ַ�������ѧ������������Ҫ��
            {
                while (getchar() != '\n');
                printf("error\n");
            }//���ӳ���׳��
            ReadScore(cname, lnum, iscore, n);
            break;
        case 2://����γ̵��ֺܷ�ƽ����
            isum = Sum(iscore, n);
            iaver = isum / n;
            printf("sum = %d, average = %d\n\n", isum, iaver);
            break;
        case 3://���ɼ��ɸߵ����ų����α�
            SelectionSort(cname, lnum, iscore, n, Descending);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ɼ���%-4d ���Σ�%-3d\n", cname[j], lnum[j], iscore[j], j + 1);
            }
            printf("\n");
            break;
        case 4://���ɼ��ɵ͵����ų����α�
            SelectionSort(cname, lnum, iscore, n, Ascending);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ɼ���%-4d ���Σ�%-3d\n", cname[j], lnum[j], iscore[j], n - j);
            }
            printf("\n");
            break;
        case 5://��ѧ����С�����ų��ɼ���
            SelectionSort_Num(cname, lnum, iscore, n);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ɼ���%-4d\n", cname[j], lnum[j], iscore[j]);
            }
            printf("\n");
            break;
        case 6://���������ֵ�˳���ų��ɼ���
            SelectionSort_Name(cname, lnum, iscore, n);
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ɼ���%-4d\n", cname[j], lnum[j], iscore[j]);
            }
            printf("\n");
            break;
        case 7://��ѧ�Ų�ѯѧ���������俼�Գɼ�
            printf("����ѧ�ţ�");
            while (!scanf("%ld", &lnumx) || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
            SelectionSort(cname, lnum, iscore, n, Descending);
            for (j = 0; j < n; j++)
            {
                if (lnum[j] == lnumx)
                {
                    printf("���Σ�%-3d �ɼ���%-4d\n\n", j + 1, iscore[j]);
                    break;
                }
            }
            if (j == n && lnum[n - 1] != lnumx)
                printf("�����ڴ�ѧ��\n\n");
            break;
        case 8://��������ѯѧ���������俼�Գɼ�
            printf("����������");
            gets(cname1);
            SelectionSort(cname, lnum, iscore, n, Descending);
            for (j = 0; j < n; j++)
            {
                if (strcmp(cname1, cname[j]) == 0)
                {
                    printf("���Σ�%-3d �ɼ���%-4d\n\n", j + 1, iscore[j]);
                    break;
                }
            }
            if (j == n && strcmp(cname1, cname[j]) != 0)
                printf("�����ڴ�����\n\n");
            break;
        case 9://�����㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣��������� (0��59��)5�����ͳ��ÿ�����������Լ���ռ�İٷֱ�
            Percentage(iscore, n);
            printf("\n");
            break;
        case 10://���ÿ��ѧ����ѧ�š����������Գɼ��Լ��γ��ֺܷ�ƽ����
            for (j = 0; j < n; j++)
            {
                printf("������%-10s ѧ�ţ�%-10ld �ɼ���%-4d\n", cname[j], lnum[j], iscore[j]);
            }
            isum = Sum(iscore, n);
            iaver = isum / n;
            printf("sum = %d, average = %d\n\n", isum, iaver);
            break;
        case 11://�˳�
            goto end;

        }
    }
end:
    ;

    return 0;
}

/*��������ReadScore
���룺ѧ����������ѧ�źͿ��Գɼ����Լ�ѧ������
���������ѧ����������ѧ�źͿ��Գɼ�
�������ܣ�¼��ѧ����������ѧ�źͿ��Գɼ�*/
void ReadScore(char cname[][N], long lnum[], int iscore[], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        while (getchar() != '\n');
        printf("��������:");
        gets(cname[i]);

        printf("����ѧ�źͳɼ���ѧ��Ϊ�����ɼ���0-100��:");
        while (scanf("%ld %d", &lnum[i], &iscore[i]) != 2 || lnum[i] <= 0 || iscore[i] < 0 || iscore[i] > 100)//��ֹ���ʹ�������������ַ�����ѧ���Լ��ɼ�������Ҫ��
        {
            while (getchar() != '\n');
            printf("input data error,please input another data:");
        }
        for(j = 0; j < i; j++)
        {
            if(i > 0 && lnum[i] == lnum[j])
            {
                i--;
                printf("ѧ���Ѵ���\n");//��֤�����ѧ�Ų���
                break;
            }
        }
    }
}

/*��������Sum
���룺ѧ���Ŀ��Գɼ�
�����ѧ�����ܳɼ�
�������ܣ�����n��ѧ���ɼ����ܷ�*/
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

/*��������SelectionSort
���룺ѧ����������ѧ�źͿ��Գɼ����Լ�ѧ�����������򷽷�
��������ɼ���/����˳�������ѧ����������ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰��ɼ���/����˳���cname��ltable����*/
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
            temp2 = lnum[k];
            lnum[k] = lnum[i];
            lnum[i] = temp2;
            /*�����ɼ�*/
            temp3 = iscore[k];
            iscore[k] = iscore[i];
            iscore[i] = temp3;
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
���룺ѧ����������ѧ�źͿ��Գɼ����Լ�ѧ������
�������ѧ������˳�������ѧ����������ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰�ѧ������˳���cname��ltable����*/
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
                k = j;//��¼��Сѧ���±�λ��
            }
        }
        if (k != i)//����Сѧ�Ų����±�λ��
        {
            /*��������*/
            strcpy(temp, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp);
            /*����ѧ��*/
            temp1 = lnum[k];
            lnum[k] = lnum[i];
            lnum[i] = temp1;
            /*�����ɼ�*/
            temp2 = iscore[k];
            iscore[k] = iscore[i];
            iscore[i] = temp2;
        }
    }
}

/*��������SelectionSort_Name
���룺ѧ����������ѧ�źͿ��Գɼ����Լ�ѧ������
��������������ֵ�˳�������ѧ����������ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰��������ֵ�˳���cname��ltable����*/
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
                k = j;//��¼��С�����±�λ��
            }
        }
        if (k != i)//����С���������±�λ��
        {
            /*��������*/
            strcpy(temp, cname[k]);
            strcpy(cname[k], cname[i]);
            strcpy(cname[i], temp);
            /*����ѧ��*/
            temp1 = lnum[k];
            lnum[k] = lnum[i];
            lnum[i] = temp1;
            /*�����ɼ�*/
            temp2 = iscore[k];
            iscore[k] = iscore[i];
            iscore[i] = temp2;
        }
    }
}

/*��������Percentage
���룺ѧ����ѧ�źͿ��Գɼ����Լ�ѧ������
�����ÿ�����������Լ���ռ�İٷֱ�
�������ܣ������㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣��������� (0��59��)5�����ͳ��ÿ�����������Լ���ռ�İٷֱ�*/
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
    printf("����:%d %.2f%%\n", inum1, (float)inum1 / n * 100);
    printf("����:%d %.2f%%\n", inum2, (float)inum2 / n * 100);
    printf("�е�:%d %.2f%%\n", inum3, (float)inum3 / n * 100);
    printf("����:%d %.2f%%\n", inum4, (float)inum4 / n * 100);
    printf("������:%d %.2f%%\n", inum5, (float)inum5 / n * 100);
}
