#include <iostream>

using namespace std;

int rsum(int);  //计算一个数所有真约数之和

int main(){
    int m;
    int a, b;
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        if(rsum(a) == b && rsum(b) == a){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    system("pause");
    return 0;
}

int rsum(int x){
    int sum = 0;
    for(int i = 1; i <= x / 2; i++){
        if(x % i == 0){
            sum += i;
        }
    }
    return sum;
}