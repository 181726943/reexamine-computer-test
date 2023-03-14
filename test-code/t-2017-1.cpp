#include "iostream"
#include "cctype"

using namespace std;

void print(char begin, char end){
	int length = end - begin +1;
	for(char ch = end; ch >= begin; ch--){
		int count = end - ch;
		//打印空格
		for(int i = 0; i < count; i++){
			cout<<' ';
		}
		//打印前半部分
		for(char s = begin; s <= ch; s++){
			cout<<s;
		}
		//打印后半部分
		for(char s = ch - 1; s >= begin; s--){
			cout<<s;
		}
		cout<<endl;
	}
}

int main(){
	char target;
	cout<<"请输入字符:";
	cin>>target;
	if(islower(target))  //小写字母
		print('a',target);
	else    //大写字母
		print('A',target);
	return 0;
}
