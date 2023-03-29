/* 
 * 青年歌手大奖赛中，评委会给参赛选手打分。
 * 选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，
 * 请编程输出某选手的得分。
 * 
 * 输入数据有多组，每组占一行，
 * 每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分
 */
#include <stdio.h>

int main(){
    int n;  //评委个数
    double scores, sum;  //sum计算总分，score记录每个评委打分
    double max,min;  //记录最高最低分
    while(scanf("%d", &n) != EOF){
        sum = 0;
        //此处设置最高最低分的值是为了能够准确的找出最高最低分
        max = -1;
        min = 101;
        for(int i = 0; i < n; i++){
            scanf("%lf", &scores);
            if(max < scores) max = scores;
            if(min > scores) min = scores;
            sum += scores;
        }
        sum = sum - max - min;  //去掉最高分最低分
        printf("%.2f\n", sum / (n-2));
    }


    return 0;
}