#include <stdio.h>

int main(){
    int a, b, res;
    while(scanf("%d %d", &a, &b) != EOF){
        if(a == 0 && b == 0)
            break;
        res = a % 1000;
        for(int i = 1; i < b; i++){
            res = res * a % 1000;
        }
        printf("%d\n", res);
    }
    return 0;
}