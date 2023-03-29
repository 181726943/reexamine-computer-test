/* 
 * 有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，
 * 现在要求你按照顺序每m个数求出一个平均值，
 * 如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。
 *
 * 输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。
 */
#include <stdio.h>

int main(){
    int m, n;
    int sum;
    while(scanf("%d %d", &n, &m) != EOF){
        sum = 0;
        int count = 0;
        for(int i = 2;i <= 2*n; i += 2){
            sum += i;
            ++count;
            if(count == m || i == 2*n){
                sum /= count;
                printf("%d", sum);
                if(i < 2*n) printf(" ");
                count = 0;
                sum = 0;
            }
        }
        printf("\n");
    }

    return 0;
}