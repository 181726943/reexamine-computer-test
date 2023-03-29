/* 
 * UTF-8
 * 求多项式的和
 * 多项式定义：1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
 * 求前n项和
 * n的值有多个
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;
    double sum;
    scanf("%d", &m);
    for (int k = 0; k < m; k++){
        scanf("%d", &n);
        sum = 0;
        for(int i = 1; i <= n; i++){
            double a = 1 / (double)i;  //把i强制类型转化，不然最后得到的是整型整除的结果
            if(i % 2 != 0){
                sum += a;
            }else{
                sum -= a;
            }
        }
        printf("%.2f\n", sum);
    }
    system("pause");
    return 0;
}