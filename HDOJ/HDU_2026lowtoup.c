/* 将英文句子中每个单词第一个字母改成大写 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char sentence[100] = {'\0'};
    while(scanf("%[^\n]%*c", sentence) != EOF){
        int len = strlen(sentence);
        for(int i = 0; i < len; i++){
            if(i == 0 && islower(sentence[0])){  //将句子首字母改成大写
                sentence[0] = toupper(sentence[0]);
                continue;
            }
            if(sentence[i] == ' '){  //将每个空格之后的第一个字符改成大写
                sentence[i] = toupper(sentence[++i]);
                continue;
            }
        }
        printf("%s\n", sentence);
    }
    return 0;
}