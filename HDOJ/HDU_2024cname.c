#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n;
    bool flag;  //指示字符串是否为合法标识符
    char id[50];
    scanf("%d", &n);
    getchar();  //吸收换行符
    for(int i = 0; i < n; i++){
        /* 
         * "%[^\n]%*c"读取字符串到\n结束读取并将\n丢弃
         */
        scanf("%[^\n]%*c", id);
        flag = true;  //默认字符串合法
        if(!isalpha(id[0]) && id[0] != '_'){  //字符串以数字开头
            printf("no\n");
            continue;
        }
        for(int i = 1; i < strlen(id); i++){
            //字符串中某个字符不是数字，字母，下划线，表示非法
            if(!isalpha(id[i]) && !isdigit(id[i]) && id[i] != '_'){
                printf("no\n");
                flag = false;  //字符串不合法
                break;
            }
        }
        if(flag){
            printf("yes\n");
        }
    }
    return 0;
}