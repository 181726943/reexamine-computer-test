/*
 *�����Ŀ����˼����eeee���ֲ�����
 *eeee�Ҳ�Ĳ���ѭ������8λ
*/
#include <iostream>
#include <vector>


using namespace std;


//��λ����
long shift(int n){
	long res;  //�洢��λ��ɺ������
	int n_e = n & 0xf0f0f0f0;  //��ȡeeee����
	int n_b = n & 0x000f0f0f;  //��ȡbbbb����
	int n_v = n & 0x0f000000;  //��ȡvvvv����
	/*eeee�Ҳಿ��ѭ������8λ*/
	n_b = n_b << 8;    //bbbb��������8Ϊλ
	n_v = n_v >> 24;
	n_b = n_b | n_v;
	
	res = n_e | n_b;
	return res;
}

int main(){
    int n;
	vector<int> res;
    cout<<"����:"<<endl;
    //��ת���������res��
    while(cin>>n){
		res.push_back(shift(n));
	}
	//���ת�����
	cout<<"���:"<<endl;
	for(auto it : res){
		cout<<it<<endl;
	}
	vector<int>().swap(res);
	return 0;
}
