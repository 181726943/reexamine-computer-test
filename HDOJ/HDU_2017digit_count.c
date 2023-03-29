/* 
 * 对于给定的一个字符串，统计其中数字字符出现的次数。
 *
 * 输入数据有多行，第一行是一个整数n，表示测试实例的个数，
 * 后面跟着n行，每行包括一个由字母和数字组成的字符串。
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[100];
    int len = 0, count = 0;
    while(scanf("%s", str) != EOF){
        len = strlen(str);
        count = 0;
        for(int i = 0; i < len; i++){
            if(isdigit(str[i])) ++count;
        }
        printf("%d\n", count);
    }
    return 0;
}