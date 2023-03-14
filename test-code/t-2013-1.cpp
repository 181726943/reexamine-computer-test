#include "iostream"
#include "cstdlib"
#include "cmath"

using namespace std;

bool isPrime(int num){  //判定素数
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    int m;
    cout<<"请输入m的值: ";
    cin>>m;
    if(m <= 0){
        cout<<"输入非法！"<<endl;
        exit(0);
    }
    if(m <= 3){
        cout<<"不存在不超过"<<m<<"的孪生素数。"<<endl;
        return 0;
    }
    for(int i = m; i > 2; i--){
        if(isPrime(i) && isPrime(i-2)){  //判定孪生素数
            cout<<"不超过m的最大孪生素数为: "<<i-2<<"和"<<i<<endl;
            break;
        }
    }
    return 0;
}
