/* 
 * 如果每个老师的工资额都知道，最少需要准备多少张人民币，
 * 才能在给每位老师发工资的时候都不用老师找零呢？
 * 这里假设老师的工资都是正整数，单位元，
 * 人民币一共有100元、50元、10元、5元、2元和1元六种。
 */
#include <stdio.h>


/* 
 * for循环里面被注释掉的内容加不加都行 
 * 只需要通过取余，整除便可以得到相应的货币数量
 */
int main(){
    int n;  //老师个数n
    int money;  //存储每个老师工资
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;  //0表示输入结束
        int count = 0;  //存储需要的钱的数量
        for(int i = 0; i < n; i++){
            scanf("%d", &money);
            count += ((money % 5) % 2);  //1元需要的数量
            count += ((money % 5) / 2);  //2元需要的数量
            count += ((money % 10) / 5);  //5元需要的数量
            count += ((money % 50) / 10);  //10元需要的数量
            count += ((money % 100) / 50);  //50需要的数量
            count += (money / 100);  //100需要的数量
        }
        printf("%d\n", count);
    }
    return 0;
}