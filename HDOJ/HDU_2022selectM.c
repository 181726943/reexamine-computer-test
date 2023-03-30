#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        int absmax, scores;
        int row = 0, column = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &scores);
                if(i == 0 && j == 0) 
                    absmax = scores;  //将absmax记为第一个数据，便于选出最大值
                if(abs(scores) > abs(absmax)){
                    absmax = scores;
                    row = i;  //最大分数所在行数
                    column = j;  //最大分数所在列数
                }
            }
        }
        printf("%d %d %d\n", row+1, column+1, absmax);
    }
    return 0;
}