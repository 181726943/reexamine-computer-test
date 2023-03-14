#include "iostream"
#include "cmath"

using namespace std;

bool isPrime(int num){  //�ж�����
    for(int i = 2; i < sqrt(num); i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    int counts = 0;  //��¼ÿ����������ĸ���
    cout<<"���е���λ��������Ϊ:"<<endl;
    for(int i = 1000; i < 10000; i++){
        if(isPrime(i) && isPrime(i/10) && isPrime(i/100) && isPrime(i/1000)){
            cout<<i<<' ';
            counts++;
            if(counts != 0 && counts % 6 == 0)
                cout<<endl;
        }
    }
    return 0;
}
