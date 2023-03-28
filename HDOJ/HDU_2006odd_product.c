/* 奇数乘积 */
#include <stdio.h>

int main(){
    int n, num;
    int product = 1;
    while(scanf("%d", &n) != EOF){
        product = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            if(num % 2 != 0){
                product *= num;
            }
        }
        printf("%d\n",product);
    }
    return 0;
}