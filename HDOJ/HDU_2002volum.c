/* 计算球体积 */
#include <stdio.h>
#include <math.h>
#define PI 3.1415927

int main(){
    double radius, vol;
    while(scanf("%lf",&radius) != EOF){
        vol = PI * pow(radius,3) * 4 / 3;
        printf("%.3lf\n", vol);
    }
    return 0;
}