#include <stdio.h>

int main()
{
    int start, end;
    printf("Enter the starting point : ");
    scanf("%d", &start);
    printf("Enter the ending point : ");
    scanf("%d", &end);

    int maxNum = start >= end ? start : end;
    int minNum = start <= end ? start : end;

    printf("Prime numbers between %d and %d are : \t", minNum, maxNum);
    for (int i = minNum; i <= maxNum; i++)
    {
        int flag = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%d\t", i);
        }
    }
}