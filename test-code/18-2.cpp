#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

//ʮ����ת������
void convert(int n){
	int bin[32] = {0};
	int i = 31;
	do{
		bin[i] = n % 2;
		n /= 2;
		i--;
	}while(n);
	for(i = 0; i < 32; i++){
		cout<<bin[i];
		if((i+1) % 8 == 0)
			cout<<' ';
	}
}

int main(){
	string s;
	char ch;
	int sum = 0;
	cout<<"�������Ƕ�������: ";
	cin>>s;
	for(auto ch : s){
		if(!isdigit(ch) && ch != 'a' && ch != 'b'){
			cout<<"input error!"<<endl;
			exit(0);
		}
	}
	//���ʮ��������ÿһλ��Ӧ��ʮ������
	for(auto c : s){
		if(isdigit(c)){
			cout<<c<<' ';
			sum = sum * 12 + (c - '0');  //ʮ������תʮ����
		}
		else if(c == 'a'){
			cout<<10<<' ';
			sum = sum * 12 + 10;
		}
		else{
			cout<<11<<' ';
			sum = sum * 12 + 11;
		}

	}
	cout<<endl;
	cout<<sum<<endl;
	convert(sum);
	return 0;
}
