#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	vector<int> arr;  //ԭ����
	int n;  //ԭ����Ԫ�ظ���
	cout<<"��������Ԫ�ظ���: ";
	cin>>n;
	while(n){
		int temp;
		cin>>temp;
		arr.push_back(temp);
		n--;
	}
	//����
	sort(arr.begin(),arr.end());
	//���
	for(auto it = arr.begin(); it != arr.end(); it++)
		cout<<left<<setw(3)<<*it;
	cout<<endl;
	//ȥ��
	set<int> unarr(arr.cbegin(), arr.cend());  //ȥ�غ������
	//���
	for(auto it = unarr.begin(); it != unarr.end(); it++)
		cout<<left<<setw(3)<<*it;
	cout<<endl;
	//�ͷ�����ռ�õĿռ�
	vector<int>().swap(arr);
	set<int>().swap(unarr);
	return 0;
}
