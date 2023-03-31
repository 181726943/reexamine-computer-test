#include <stdio.h>

/* 
 * 注意本题中所有整型数据使用long long型
 * 否则oj会报Wrong Answer
 */
long long gcd(long long, long long);

int main(){
    long long n;
    while(scanf("%lld",&n) != EOF){
        if(n == 0)
            continue;
        long long num1 = 0, num2;
        long long i = 0;
        while(num1 == 0 && i < n){
            scanf("%lld", &num1);
            ++i;
        }
        for(; i < n; i++){
            scanf("%lld", &num2);
            if(num2 == 0){
                continue;
            }
            //两两计算最大公倍数
            num1 = num1 * num2 / gcd(num1,num2);
        }
        printf("%lld\n", num1);
    }
    return 0;
}

long long gcd(long long a, long long b){
    long long c;
    if(a < b){
        long long temp = a;
        a = b;
        b = temp;
    }
    while(b){
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}