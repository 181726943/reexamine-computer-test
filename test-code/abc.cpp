/*
 *12345
*/
#include <iostream>
#include <cmath>

using namespace std;

//1234
bool isprime(long n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return false;
	}
	return true;
}
/*
 //*4568418hlkhkgiugkhk
 *jfaldienf e9525
*/
int main(){
	long N;   //jfiajfe
	cout<<"请输入一个长整数: ";
	cin>>N;
	int maxp = log10(N+1) / log10(2);  //jal/**/dfjio32
	for(long p = 2; p < maxp; p++){
		long n = pow(2,p) - 1;   //jfa/*ds4561
		if(isprime(n)){
			cout<<"M("<<p<<")="<<n<<endl;  //afdjleijfeiajf787
		}
	}
	return 0;
}