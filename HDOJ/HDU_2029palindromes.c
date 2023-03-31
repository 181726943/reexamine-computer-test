#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int n;
    char str[100] = {'\0'};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        int len = strlen(str);  //字符串长度
        bool flag = true;  //回文字符串标志，默认为真，即该字符串是回文字符串
        for(int k = 0; k < n/2; k++){
            if(str[k] != str[len-k-1]){  //采用首尾判断法
                flag = false;
                break;
            }
        }
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    system("pause");
    return 0;
}