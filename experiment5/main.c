/* �ļ���: experiment5
������: ����
�� ��: 2020.10.26.
������ѧ���ɼ�����ϵͳ
�汾��1.0
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
    printf("Subject No.5\n\n");//�ļ���Ϣ

    int ichoice, score[N], isum, iaver, n, i, j;//ichoiceΪ�û������ѡ�score[N]Ϊѧ���ɼ���isumΪ�ܳɼ���iaverΪƽ���ɼ�, nΪ������
    long num[N], lnum;//num[N]Ϊѧ��ѧ��, lnumΪ�����ѯ�ĵ�ѧ��ѧ��

    printf("ѧ���ɼ�����ϵͳ1.0\n\n");

    for (i = 0;; i++)
    {
        //����˵��������û���ѡ��
        printf("1��Input record\n");
        printf("2. Calculate total and average score of course\n");
        printf("3. Sort in descending order by score\n");
        printf("4. Sort in ascending order by score\n");
        printf("5. Sort in ascending order by number\n");
        printf("6��Search by number\n");
        printf("7��Statistic analysis\n");
        printf("8��List record\n");
        printf("0��Exit\n");
        printf("Please enter your choice:\n");

        while (!scanf("%d", &ichoice) || ichoice < 0 || ichoice > 8 || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�
        {
            while (getchar() != '\n');
            printf("error\n");
        }//���ӳ���׳�ԣ������û���ѡ��ת����Ӧ�Ĳ���

        switch (ichoice)
        {
        case 1://¼��ÿ��ѧ����ѧ�źͿ��Գɼ�
            printf("����ѧ��������1-30����");
            while (!scanf("%d", &n) || n < 1 || n > 30 || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�������ѧ������������Ҫ��
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
            ReadScore(score, num, n);
            break;
        case 2://����γ̵��ֺܷ�ƽ����
            isum = Sum(score, n);
            iaver = isum / n;
            printf("sum = %d, average = %d\n\n", isum, iaver);
            break;
        case 3://���ɼ��ɸߵ����ų����α�
            SelectionSort(score, num, n, Descending);
            for (j = 0; j < n; j++)
            {
                printf("ѧ�ţ�%10ld �ɼ���%4d ���Σ�%3d\n", num[j], score[j], j + 1);
            }
            printf("\n");
            break;
        case 4://���ɼ��ɵ͵����ų����α�
            SelectionSort(score, num, n, Ascending);
            for (j = 0; j < n; j++)
            {
                printf("ѧ�ţ�%10ld �ɼ���%4d ���Σ�%3d\n", num[j], score[j], n - j);
            }
            printf("\n");
            break;
        case 5://��ѧ����С�����ų��ɼ���
            SelectionSort_Num(score, num, n);
            for (j = 0; j < n; j++)
            {
                printf("ѧ�ţ�%10ld �ɼ���%4d\n", num[j], score[j]);
            }
            printf("\n");
            break;
        case 6://��ѧ�Ų�ѯѧ���������俼�Գɼ�
            printf("�������ѯѧ�ţ�");
            while (!scanf("%ld", &lnum) || getchar() != '\n')//��ֹ���ʹ��󣬻�������ȷ����ֵ����������ַ��������������ַ�
            {
                while (getchar() != '\n');
                printf("input data error,please input another data:");
            }
            SelectionSort(score, num, n, Descending);
            for (j = 0; j < n; j++)
            {
                if (num[j] == lnum)
                {
                    printf("���Σ�%3d �ɼ���%4d\n\n", j + 1, score[j]);
                    break;
                }
            }
            if (j == n && num[n - 1] != lnum)
                printf("�����ڴ�ѧ��\n\n");
            break;
        case 7://�����㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣��������� (0��59��)5�����ͳ��ÿ�����������Լ���ռ�İٷֱ�
            Percentage(score, num, n);
            printf("\n");
            break;
        case 8://���ÿ��ѧ����ѧ�š����Գɼ��Լ��γ��ֺܷ�ƽ����
            for (j = 0; j < n; j++)
            {
                printf("ѧ�ţ�%10ld �ɼ���%4d\n", num[j], score[j]);
            }
            isum = Sum(score, n);
            iaver = isum / n;
            printf("sum = %d, average = %d\n\n", isum, iaver);
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
���룺ѧ���ĸ�����ѧ�źͿ��Գɼ�
���������ѧ����ѧ�źͿ��Գɼ�
�������ܣ�¼��ѧ����ѧ�źͿ��Գɼ�*/
void ReadScore(int score[], long num[], int n)
{
    int i, j;//��֤����ѭ���������±��0��ʼ

    for (i = 0; i < n; i++)
    {
        printf("����ѧ�źͳɼ���������С��0��:");
        while (scanf("%ld %d", &num[i], &score[i]) != 2 || num[i] <= 0 || score[i] < 0 || score[i] > 100|| getchar() != '\n')//��ֹ���ʹ�������������ַ�����ѧ���Լ��ɼ�������Ҫ��
        {
            while (getchar() != '\n');
            printf("input data error,please input another data:");
        }
        for(j = 0; j < i; j++)
        {
            if(i > 0 && num[i] == num[j])
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
int Sum(int score[], int n)
{
    int i, isum = 0;
    for(i = 0; i < n; i++)
    {
        isum += score[i];
    }
    return isum;
}

/*��������SelectionSort
���룺ѧ����ѧ�źͿ��Գɼ����Լ�ѧ�����������򷽷�
��������ɼ���/����˳�������ѧ����ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰�score����Ԫ�ؽ�/����˳���score��num����*/
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
                k = j;//��¼���/С���±�λ��
            }
        }
        if (k != i)//�����/С�������±�λ��
        {
            /*�����ɼ�*/
            temp1 = score[k];
            score[k] = score[i];
            score[i] = temp1;
            /*����ѧ��*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
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
���룺ѧ����ѧ�źͿ��Գɼ����Լ�ѧ������
�������ѧ������˳�������ѧ����ѧ�źͿ��Գɼ�
�������ܣ���ѡ�񷨰�num����Ԫ������˳���score��num����*/
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
                k = j;//��¼��Сѧ���±�λ��
            }
        }
        if (k != i)//����Сѧ�Ų����±�λ��
        {
            /*�����ɼ�*/
            temp1 = score[k];
            score[k] = score[i];
            score[i] = temp1;
            /*����ѧ��*/
            temp2 = num[k];
            num[k] = num[i];
            num[i] = temp2;
        }
    }
}

/*��������Percentage
���룺ѧ����ѧ�źͿ��Գɼ����Լ�ѧ������
�����ÿ�����������Լ���ռ�İٷֱ�
�������ܣ������㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣��������� (0��59��)5�����ͳ��ÿ�����������Լ���ռ�İٷֱ�*/
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
    printf("����:%d %.2f%%\n", inum1, (float)inum1 / n * 100);
    printf("����:%d %.2f%%\n", inum2, (float)inum2 / n * 100);
    printf("�е�:%d %.2f%%\n", inum3, (float)inum3 / n * 100);
    printf("����:%d %.2f%%\n", inum4, (float)inum4 / n * 100);
    printf("������:%d %.2f%%\n", inum5, (float)inum5 / n * 100);

}
