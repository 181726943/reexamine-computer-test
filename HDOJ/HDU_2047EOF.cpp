/* 
 * 设设满足定义i长度的字符串有num[i]种，并且字符串中的字符的下标为1~n，
 * 由题知num[0]=0、num[1]=3、num[2]=8，当长度为n(n>=3)时，推导过程如下：
 * (1)若第n个字符为O，假定1~n-2满足题目的要求，那么第n-1个位置上的字符不能为O，
 *    只能为E或者F，所以总数为2 *num(n-2)；
 * (2)若第n个字符不为O，假定1~n-1题目的要求，那么第n个位置上的字符只能为E或者F，
 *    所以总数为2*num(n-1)
 * 所以可得到递推式num[n]=2*(num[n-1]+num[n-2])
*/
#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        __int64 old = 1, fresh = 3;
        for(int i = 1; i <n; i++){
            fresh = 2 * (fresh + old);
            old = fresh / 2 - old;
        }
        cout<<fresh<<endl;
    }
    return 0;
}