/* 
 * 判定素数
 * 对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，
 * 判定该表达式的值是否都为素数。
 * 
 * 输入数据有多组，每组占一行，
 * 由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int);

int main(){
    int x, y;
    int count;  //记录素数个数
    while(scanf("%d %d", &x, &y) != EOF){
        if(x == 0 && y == 0) continue;
        count = 0;
        for(int i = x; i <= y; i++){
            if(isprime(pow(i,2) + i + 41) == 0){
                printf("Sorry\n");
                break;
            }else{
                ++count; 
            }
        }
        if(count == y - x + 1) printf("OK\n");
    }
    return 0;
}

int isprime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
        
    }
    return 1;
}