#include <iostream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

int main(){
    string s;
    map<char,int>cmap;  //��¼Ӣ�ľ�����ÿ����ĸ���ֵĴ���
    int alpha = 0,word = 0;  //alpha--��ĸ����,word--���ʸ���
    string amax;  //��¼���ִ���������ĸ
    int times = 0;  //��¼���ִ���������ĸ���ֵĴ���
    cout<<"������Ӣ�ľ���: ";
    getline(cin, s);
//	cin>>noskipws;  //����cin��ȡ�ո�
//	cin>>s;
    for(auto ch : s){
        if(isalpha(ch))
            alpha++;
        if(ch == ' ')
            word++;
        if(ch != ' ')
            cmap[tolower(ch)]++;
    }
    word++;  //ͨ���ո�����жϵ��ʸ��������ʸ����ȿո������1
    cout<<"��ĸ����: "<<alpha<<endl;
    cout<<"���ʸ���: "<<word<<endl;
    //���ҳ��ִ�������Ԫ��
    for(auto it = cmap.cbegin(); it != cmap.cend(); it++){
         if(times < it->second){
            times = it->second;
         }
    }
    for(auto it = cmap.cbegin(); it != cmap.cend(); it++)
        if(it->second == times)
            amax.push_back(it->first);
    cout<<"������ĸ: ";
    for(decltype(amax.size()) i = 0; i < amax.size(); i++){
        cout<<amax[i];
        if(i != amax.size()-1){
            cout<<",";
        }
    }
    cout<<endl;
    cout<<"���ֵĴ���: "<<times<<endl;
    system("pause");
    return 0;
}
