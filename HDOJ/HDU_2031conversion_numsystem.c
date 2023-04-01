#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conversion(int, int, char[]);

int main(){
    int N, R;  //N表示十进制数，R表示要转化的进制
    while(scanf("%d %d", &N, &R) != EOF){
        char res[32] = {'\0'};  //存储结果
        int len = conversion(N, R, res);
        if(N < 0)
            printf("-");  //N为负数，要提前输出一个负号
        for(int i = len-1; i >= 0; i--){
            if(res[i] < 10)
                printf("%d", res[i]);
            else
                printf("%c",res[i]);
        }
        printf("\n");
    }
    return 0;
}

int conversion(int N, int R, char res[]){
    if(N == 0){
        res[0] = '0';
        return 1;  //转化之后的数长度为1
    }
    int i = 0, num = abs(N), digit;
    while(num){
        digit = num % R;
        if(digit < 10)
            res[i] = (char)digit;
        else{
            switch (digit)
            {
            case 10:
                res[i] = 'A';
                break;
            case 11:
                res[i] = 'B';
                break;
            case 12:
                res[i] = 'C';
                break;
            case 13:
                res[i] = 'D';
                break;
            case 14:
                res[i] = 'E';
                break;
            case 15:
                res[i] = 'F';
                break;
            default:
                break;
            }
        }
        num = num / R;
        i++;
    }
    return i;  //返回字符串长度
}