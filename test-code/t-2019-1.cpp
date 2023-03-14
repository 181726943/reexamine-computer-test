/*
 *��÷ɭ����
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


//�ж�����
bool isprime(long n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

/*
 *÷ɭ������ָ���� 2^p��1 ��һ����������ָ��p�Ǵ��ڵ���2��������������ΪM�� ��
 *���÷ɭ�����������ͳ�Ϊ÷ɭ������
*/

int main(){
	long N;   //������N
	cout<<"������һ��������: ";
	cin>>N;
	int maxp = log10(N+1) / log10(2);  //���ָ��p�����ֵ
	for(long p = 2; p < maxp; p++){
		long n = pow(2,p) - 1;   //��÷ɭ��
		if(isprime(n)){
			cout<<"M("<<p<<")="<<n<<endl;  //������ĿҪ��ĸ�ʽ���÷ɭ����
		}
	}
	return 0;
}
