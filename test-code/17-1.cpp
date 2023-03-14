#include "iostream"
#include "cctype"

using namespace std;

void print(char begin, char end){
	int length = end - begin +1;
	for(char ch = end; ch >= begin; ch--){
		int count = end - ch;
		//��ӡ�ո�
		for(int i = 0; i < count; i++){
			cout<<' ';
		}
		//��ӡǰ�벿��
		for(char s = begin; s <= ch; s++){
			cout<<s;
		}
		//��ӡ��벿��
		for(char s = ch - 1; s >= begin; s--){
			cout<<s;
		}
		cout<<endl;
	}
}

int main(){
	char target;
	cout<<"�������ַ�:";
	cin>>target;
	if(islower(target))  //Сд��ĸ
		print('a',target);
	else    //��д��ĸ
		print('A',target);
	return 0;
}
