#include <iostream>

using namespace std;

int main(){
    int n;  //测试实例的个数
    double a, b, c;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a>>b>>c;
        if(a + b <= c || a + c <= b || b + c <= a || !a || !b || !c){
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
    return 0;
}