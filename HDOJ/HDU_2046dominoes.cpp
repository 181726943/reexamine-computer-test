/* 
 * 递推式dom[i]=dom[i-1]+dom[i-2]
 * 同时还要注意int类型无法存放很大的结果，可以用_int64(c语言)
*/

#include <iostream>

using namespace std;

int main(){
    int n;  //2xn型方格
    while(cin>>n){
        __int64 old = 0, neo = 1;
        for(int i = 1; i <= n; i++){
            neo = old + neo;
            old = neo - old;
        }
        cout<<neo<<endl;
    }
    return 0;
}