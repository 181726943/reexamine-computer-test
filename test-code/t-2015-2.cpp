#include "iostream"
#include "cstring"
#include "string"

using namespace std;

int main(){
    string s1,s2;
    string res;
    cout<<"�����������ַ���: ";
    cin>>s1>>s2;
    //ƴ��
    res = s1 + s2;
    cout<<"ƴ�Ӻ���ַ���: "<<res<<endl;
    s1.erase();  s2.erase();
    //����
    for(int i = 0; i < res.size(); i++){
        if(i % 2 == 0)
            s1 += res[i];
        else
            s2 += res[i];
    }
    cout<<"�������ַ���: "<<s1<<' '<<s2<<endl;
    //����
    for(int i = 0; i < s1.size(); i++){
        for(int j = i+1; j < s1.size(); j++){
            if(s1[i] > s1[j]){
                char temp = s1[i];
                s1[i] = s1[j];
                s1[j] = temp;
            }
        }
    }
    for(int i = 0; i < s2.size(); i++){
        for(int j = i+1; j < s2.size(); j++){
            if(s2[i] > s2[j]){
                char temp = s2[i];
                s2[i] = s2[j];
                s2[j] = temp;
            }
        }
    }
    cout<<"�������ַ���:"<<s1<<' '<<s2;
    return 0;
}
