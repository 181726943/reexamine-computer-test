#include <stdio.h>

long long fact(int);  //求n的阶乘
void combination(int);  //打印杨辉三角的一层

//本题用组合公式计算可以得出正确答案，但是在oj中会Wrong Answer
int main(){
    int plies;  //杨辉三角层数
    int tri[100][100] = {0};
    while(scanf("%d",&plies) != EOF){
        //建立杨辉三角
        for(int i = 0; i < plies; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    tri[i][j] = 1;
                }else{
                    tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
                }
            }
        }
        //打印杨辉三角
        for(int k = 0; k < plies; k++){
            for(int l = 0; l <= k; l++){
                if(l != 0)
                    printf(" ");
                printf("%d", tri[k][l]);
            }
            printf("\n");
        }
        printf("\n");
        // for(int f = 0; f < plies; f++){
        //     // combination(f);
        // }
        // printf("\n");  //分隔每一个实例输出
    }
    return 0;
}

long long fact(int n){  //阶乘函数
    if(n == 0){
        return 1;
    }else{
        return n * fact(n-1);
    }
}
/* 
 * 杨辉三角的n层的数实质上就是指数为(a+b)^n中每一项的系数
 * 而这个系数又可以用组合公式求出C(n,m) = n! / (m! * (n-m!))
*/
void combination(int n){
    long long coefficient;  //系数
    long long numerator = 1;  //组合公式中的分子
    long long denominator = 1;  //组合公式中的分母
    numerator = fact(n);
    for(int i = 0; i <= n; i++){
        denominator = fact(i) * fact(n-i);
        coefficient = numerator / denominator;
        if(i != 0)
            printf(" ");
        printf("%d", coefficient);
    }
    printf("\n");
}
