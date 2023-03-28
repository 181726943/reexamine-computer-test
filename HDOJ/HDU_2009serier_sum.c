/* 
 * 求数列的前m项和
 * 数列定义：
 * 第一项为n，以后各项为前一项的平方根
 */
#include <stdio.h>
#include <math.h>

int main(){
    int n, m;
    double t, sum;
    while(scanf("%d %d", &n, &m) != EOF){
        t = (double)n;
        sum = 0;
        for(int i = 0; i < m; i++){
            sum += t;
            t = sqrt(t);
        }
        printf("%.2f\n", sum);
    }
    return 0;
}