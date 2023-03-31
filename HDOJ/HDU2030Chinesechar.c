#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char string[1000] = {'\0'};
    scanf("%d", &n);
    getchar();  //处理输入整数后的换行符
    for(int i = 0; i < n; i++){
        scanf("%[^\n]%*c", string);  //读取给定文本
        int lenth = strlen(string);  //统计文本长度
        int sum = 0;
        for(int k = 0; k < lenth; k++){  
            //汉字（中文字符）的ASCII码值小于0
            //但这样统计有个问题，就是中文符号也会被统计进去
            if(string[k] < 0)
                ++sum;
        }
        printf("%d\n", sum/2);  //C语言中每个汉字占两个char字符位置
    }
    return 0;
}