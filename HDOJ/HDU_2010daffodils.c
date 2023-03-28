/* 
* 统计指定范围内水仙花数个数
* 水仙花数：它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3
*/
#include <stdio.h>
#include <math.h>

int main(){
    int m, n;
    int hund, deca, unit;  //分别表示每一位上的数字
    int flag = 0;  //用于标记从m到n的范围内是否有水仙花数
    while(scanf("%d %d", &m, &n) != EOF){
        flag = 0;
        for(int i = m; i <= n; i++){
            hund = i / 100;
            deca = (i / 10) % 10;
            unit = i % 10;
            if((pow(hund, 3) + pow(deca, 3) + pow(unit, 3)) == i){
                if(flag != 0) printf(" ");  //控制空格的打印
                printf("%d", i);
                ++flag;
            }
        }
        if(flag == 0) printf("no");
        printf("\n");
    }
    return 0;
}