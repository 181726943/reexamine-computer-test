#include <stdio.h>

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        int score[50][5] = {0};  //记录每个学生每门课的成绩
        double stu_ava[50] = {0};  //记录每个学生平均成绩
        double cou_ava[5] = {0};  //记录每门课平均成绩
        int num = 0;  //记录所有成绩都大于平均成绩的学生数量
        //学生成绩大于等于平均成绩标志
        //1：所有成绩都大于等于平均成绩
        //0：有成绩小于平均成绩
        int flag = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &score[i][j]);
                stu_ava[i] += (double)score[i][j];
                cou_ava[j] += (double)score[i][j];
            }
            stu_ava[i] = stu_ava[i] / m;  //每个学生平均成绩
        }
        for(int i = 0; i < n; i++){
            if(i != 0)
                printf(" ");  //成绩之间打印空格
            printf("%.2f", stu_ava[i]);
        }
        printf("\n");
        for(int i = 0; i < m; i++){
            cou_ava[i] /= n;  //计算每门课的平均成绩
            if(i != 0)
                printf(" ");
            printf("%.2f",cou_ava[i]);
        }
        printf("\n");
        //统计所有成绩大于等于平均成绩的学生数量
        for(int i = 0; i < n; i++){
            flag = 1;
            for(int j = 0; j < m; j++){
                if(score[i][j] < cou_ava[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                ++num;  //合格学生+1
        }
        printf("%d\n\n",num);
    }
    return 0;
}