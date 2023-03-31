#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    char str[100];  //存储字符串
    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        int sum[5] = {0};  //记录每个元音字母出现的次数
        int len = strlen(str);
        //统计
        for(int k = 0; k < len; k++){
            switch (str[k])
            {
            case 'a':
                ++sum[0];
                break;
                
            case 'e':
                ++sum[1];
                break;

            case 'i':
                ++sum[2];
                break;

            case 'o':
                ++sum[3];
                break;

            case 'u':
                ++sum[4];
                break;
            
            default:
                break;
            }
        }
        //输出
        for(int m = 0; m < 5; m++){
            printf("%c:%d\n", vowel[m], sum[m]);
        }
        if(i != n-1)
            printf("\n");

    }
    system("pause");
    return 0;
}