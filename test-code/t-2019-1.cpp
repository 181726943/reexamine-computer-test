/*
 *求梅森素数
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


//判断素数
bool isprime(long n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

/*
 *梅森数，是指形如 2^p－1 的一类数，其中指数p是大于等于2的正整数，常记为M§ 。
 *如果梅森数是素数，就称为梅森素数。
*/

int main(){
	long N;   //长整数N
	cout<<"请输入一个长整数: ";
	cin>>N;
	int maxp = log10(N+1) / log10(2);  //求出指数p的最大值
	for(long p = 2; p < maxp; p++){
		long n = pow(2,p) - 1;   //求梅森数
		if(isprime(n)){
			cout<<"M("<<p<<")="<<n<<endl;  //按照题目要求的格式输出梅森素数
		}
	}
	return 0;
}
