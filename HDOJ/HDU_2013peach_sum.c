/* 
 * 第一天悟空吃掉桃子总数一半多一个，第二天又将剩下的桃子吃掉一半多一个，
 * 以后每天吃掉前一天剩下的一半多一个，到第n天准备吃的时候只剩下一个桃子。
 * 给定n，求桃子总数
*/
#include <stdio.h>

int main(){
    int n, sum;
    while(scanf("%d", &n) != EOF){
        sum = 1;
        //通过数学分析，每天剩下的数量正好是前一天的一半少一个
        for(int i = n; i > 1; i--){
            sum = (sum + 1) * 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}