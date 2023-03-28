/* 统计给定的n个数中0以及正负数的个数 */
#include <stdio.h>

int main(){
    int n;
    double digit;
    int num0 = 0, numneg = 0, numpos = 0;  //分别表示0，负数整数的个数
    while(scanf("%d", &n) != EOF){
        if(n == 0) continue;
        numneg = 0;
        num0 = 0;
        numpos = 0;
        for(int i = 0; i < n; i++){
            scanf("%lf", &digit);
            if(digit > 0) ++numpos;
            else if (digit < 0) ++numneg;
            else ++num0;
        }
        printf("%d %d %d\n", numneg, num0, numpos);
    }
    return 0;
}