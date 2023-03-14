#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	vector<int> arr;  //原数组
	int n;  //原数组元素个数
	cout<<"输入数组元素个数: ";
	cin>>n;
	while(n){
		int temp;
		cin>>temp;
		arr.push_back(temp);
		n--;
	}
	//排序
	sort(arr.begin(),arr.end());
	//输出
	for(auto it = arr.begin(); it != arr.end(); it++)
		cout<<left<<setw(3)<<*it;
	cout<<endl;
	//去重
	set<int> unarr(arr.cbegin(), arr.cend());  //去重后的数组
	//输出
	for(auto it = unarr.begin(); it != unarr.end(); it++)
		cout<<left<<setw(3)<<*it;
	cout<<endl;
	//释放数组占用的空间
	vector<int>().swap(arr);
	set<int>().swap(unarr);
	return 0;
}
