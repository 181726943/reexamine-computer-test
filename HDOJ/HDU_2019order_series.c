/* 
 * 有n(n<=100)个整数，已经按照从小到大顺序排列好，
 * 现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。
 */
#include <stdio.h>

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
    if(m == 0 && n == 0) break;
    int flag = 0;
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        if(i != 0) printf(" ");
        if(m < temp && flag == 0){
            printf("%d %d", m, temp);
            flag = 1;
        }
        else{
            printf("%d",temp);
        }
    }
    //循环结束，flag仍然为0表示m一直没有输出，说明m是最大的
    if(flag == 0) printf(" %d", m);
    printf("\n");
    }
    return 0;
}