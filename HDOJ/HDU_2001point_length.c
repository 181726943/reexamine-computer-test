/* 两点之间的距离 */
#include <stdio.h>
#include <math.h>

int main(){
    double x1, y1, x2, y2, lenx, leny;
    double len;
    while(scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF){
        lenx = fabs(x1 - x2);  //求两个点横坐标距离
        // printf("%d\n", lenx);
        leny = fabs(y1 - y2);  //求两个点纵坐标距离,注意用求浮点数绝对值得函数
        // printf("%d\n", leny);
        len = hypot(lenx, leny);  //利用函数求两个点距离
        printf("%.2f\n",len);
    }

    return 0;
}