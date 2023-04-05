#include <iostream>

using namespace std;

int main(){
    int N;  //测试实例个数
    int a;  //收费站数量
    int sum;  //羊的总数
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>a;
        sum = 3;
        for(int k = 0; k < a; k++){
            sum = (sum - 1) * 2;
        }
        cout<<sum<<endl;
    }

    return 0;
}