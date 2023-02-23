/*文件名: Subject No.1 - program No.2
创建人: 宗晴
描述: 将输入一个小字英文字符转换为大写字符后，打印图案*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110513\n");
    printf("Subject No.1 - program No.2\n\n");//文件信息

    char low, cap;
    int i, j, k;//定义变量

    printf("Input the lowercase:");
    scanf("%c", &low);
    while (low < 'a' || low  > 'z' || getchar() != '\n')
    {
        while (getchar() != '\n');
        printf("input data error,please input another data:");
        scanf(" %c", &low);
    }//输入一个小写英文字符，同时防止非法输入以及输入多个字符

    cap = low + 'A' - 'a';//将输入的小写英文字符转换成大写

    for (i = 0; i < 8; i++)
    {
       if (i & 1)//特色：用了按位与操作判断奇偶性
       {
           printf(" ");
       }
       for (j = 0; j < 8; j++)
       {
           printf("%c ", cap);
       }
       printf("\n");
    }//输出打印图案，特色：打印图案部分仅使用了三次输出语句；

    return 0;
}
