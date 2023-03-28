/* 给定一个日期，输出这个日期是该年的第几天 */
#include <stdio.h>

int main(){
    //用数组存储每月的天数
    int month_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31,30, 31, 30, 31};
    int year, month, day;
    int total = 0, flag = 0;
    while(scanf("%d/%d/%d",&year, &month, &day) != EOF){
        total = 0;
        if((year % 400 == 0 || (year % 4 == 0 && year %100 != 0)) && month > 2){ 
            ++total;  //如果为闰年，二月多一天
        }
        //for循环计算到month月初的天数
        for(int i = 1; i < month; i++){
            total += month_day[i];
        }
        total += day;  //加上本月的天数
        printf("%d\n", total);
    }
    return 0;
}