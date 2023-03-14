/*
 *这道题目的意思就是eeee部分不动，
 *eeee右侧的部分循环左移8位
*/
#include <iostream>
#include <vector>


using namespace std;


//移位函数
long shift(int n){
	long res;  //存储移位完成后的数据
	int n_e = n & 0xf0f0f0f0;  //提取eeee部分
	int n_b = n & 0x000f0f0f;  //提取bbbb部分
	int n_v = n & 0x0f000000;  //提取vvvv部分
	/*eeee右侧部分循环左移8位*/
	n_b = n_b << 8;    //bbbb部分左移8为位
	n_v = n_v >> 24;
	n_b = n_b | n_v;
	
	res = n_e | n_b;
	return res;
}

int main(){
    int n;
	vector<int> res;
    cout<<"输入:"<<endl;
    //将转化结果存入res中
    while(cin>>n){
		res.push_back(shift(n));
	}
	//输出转化结果
	cout<<"输出:"<<endl;
	for(auto it : res){
		cout<<it<<endl;
	}
	vector<int>().swap(res);
	return 0;
}
