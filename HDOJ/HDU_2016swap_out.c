/* 
 * 输入n(n<100)个数，找出其中最小的数，
 * 将它与最前面的数交换后输出这些数。
 */
#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        else{
            int a[100];
            int min = 0;
            for(int i = 0; i < n; i++){
                scanf("%d", &a[i]);
                if(a[i] < a[min]) min = i;  //定位最小的数
            }
            int temp = a[min];
            a[min] = a[0];
            a[0] = temp;
            for(int i = 0; i < n; i++){
                printf("%d", a[i]);
                if(i !=  n-1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}