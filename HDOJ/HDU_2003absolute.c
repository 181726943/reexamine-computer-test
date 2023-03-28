/* 输出绝对值 */
#include <stdio.h>
#include <math.h>

int main(){
    double input;
    while(scanf("%lf", &input) != EOF){
        if(input < 0)
            input = -input;
        printf("%.2f\n", input);
        /* 或者直接写成下面 */
        // printf("%.2lf", fabs(input));
    }
    return 0;
}