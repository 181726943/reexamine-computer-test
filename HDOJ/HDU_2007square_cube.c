/* 一个连续的序列中奇数立方和和偶数平方和 */
#include <stdio.h>
#include <math.h>

int main()
{
    int start, end;
    int sum_squ, sum_cube;
    while (scanf("%d %d", &start, &end) != EOF)
    {
        if (start > end)
        {
            int temp = start;
            start = end;
            end = temp;
        }
        sum_squ = 0;
        sum_cube = 0;
        for (int i = start; i <= end; i++)
        {
            if (i % 2 == 0)
            { // 偶数平方和
                sum_squ += (int)pow(i, 2);
            }
            else
            { // 奇数立方和
                sum_cube += (int)pow(i, 3);
            }
        }
        printf("%d %d\n", sum_squ, sum_cube);
    }
    return 0;
}