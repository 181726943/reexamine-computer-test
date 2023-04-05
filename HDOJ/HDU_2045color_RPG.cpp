/* 
 * 递推式：s[i]=s[i-1]+2*s[i-2]（i>=5）
 * 原理解释：
 * (1)当n=i-1时，满足要求的涂法有s[i-1]种，若n=i，则在原来i-1个方格的基础上，
 * 由于第i-1个方格的颜色与第一个方格的颜色不同，且也不能与第i个方格的相同，
 * 所以第i个方格只有一种颜色可以选择，此时s[i]=s[i-1]；
 * (2)当n=i-2时，满足要求的涂法有s[i-2]种，
 * 若n=i，此时第i-1个方格只有2种颜色可以选择（与第i-2个方格的颜色不同即可），
 * 第i个方格课选择的颜色与上面一种情况同理，只有一种颜色可以选择，所以此时s[i]=2*s[i-2]；
 * 而当i>=5时，第i-3个方格所选择的颜色不能够影响s[i]的值（这里类似于2041超级楼梯），
 * 所以只有第i-1和第i-2个方格的颜色的选择可以影响s[i]的值，
 * 所以综合上述两种情况，可以得到上面的递推式。
*/

#include <iostream>

using namespace std;

int main(){
    int N;
    while(cin>>N){
        if(N == 1){
            cout<<3<<endl;
        }
        else if(N == 2 || N == 3){
            cout<<6<<endl;
        }else{
            long long old = 6, news = 6;
            for(int i = 3; i < N; i++){
                news = news + 2 * old;
                old = news - 2 * old;
            }
            cout<<news<<endl;
        }
    }
    return 0;
}