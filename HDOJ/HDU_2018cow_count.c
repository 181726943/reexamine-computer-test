/* 
 * 有一头母牛，它每年年初生一头小母牛。
 * 每头小母牛从第四个年头开始，每年年初也生一头小母牛。
 * 请编程实现在第n年的时候，共有多少头母牛？ 
 */
#include <stdio.h>

int sum_cow(int);  //计算第n年母牛总数

int main(){
    int n, sum;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        sum = sum_cow(n);
        printf("%d\n", sum);
    }
    return 0;
}

int sum_cow(int n){
    if(n < 4) return n;
    else return sum_cow(n-1) + sum_cow(n-3);
}