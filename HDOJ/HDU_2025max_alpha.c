#include <stdio.h>
#include <string.h>

int main(){
    char str[100] = {'\0'};
    while(scanf("%s",str) != EOF){
        int len = strlen(str);
        char maxch = str[0];
        //寻找最大的字符
        for(int i = 0; i < len; i++){
            if(maxch < str[i]){
                maxch = str[i];
            }
        }
        for(int i = 0; i < len; i++){
            printf("%c", str[i]);
            if(str[i] == maxch)
                printf("(max)");
        }
        printf("\n");
    }
    return 0;
}