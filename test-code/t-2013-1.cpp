#include "iostream"
#include "cstdlib"
#include "cmath"

using namespace std;

bool isPrime(int num){  //�ж�����
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    int m;
    cout<<"������m��ֵ: ";
    cin>>m;
    if(m <= 0){
        cout<<"����Ƿ���"<<endl;
        exit(0);
    }
    if(m <= 3){
        cout<<"�����ڲ�����"<<m<<"������������"<<endl;
        return 0;
    }
    for(int i = m; i > 2; i--){
        if(isPrime(i) && isPrime(i-2)){  //�ж���������
            cout<<"������m�������������Ϊ: "<<i-2<<"��"<<i<<endl;
            break;
        }
    }
    return 0;
}
