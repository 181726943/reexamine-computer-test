#include "iostream"
#include "string"
#include "cctype"

using namespace std;

int main(){
    string s;
    cout<<"�������ַ���: ";
    getline(cin,s);
    bool flag = false;  //����ַ���ǰ���Ƿ��ǿո�
    int count = 0;  //��¼�ַ����ײ��ո����
    //ȥ���ַ����ײ��ո�
    if(s[0] == ' ')
        flag = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' && flag){
            flag = true;
            count++;
        }else{
            flag = false;
            break;
        }
    }
    s.erase(0,count);
//    cout<<"ȥ���ײ��ո����ַ���: "<<s<<endl;
    //�����м�ո�
    //flag=false��ʾǰһ���ַ��ǿո�flag=true��ʾǰ�����пո�
    flag = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            if(flag){
                s.erase(i,1);
                i--;
            }
            flag = true;
        }else
            flag = false;
    }

    //�����ֺ���ĸ֮�����_
    for(int i = 0; i < s.size(); i++){
        if((isdigit(s[i]) && isalpha(s[i+1])) || (isalpha(s[i]) && isdigit(s[i+1]))){
            s.insert(i+1, 1, '_');
        }
    }
    cout<<"����֮����ַ���: "<<s<<endl;

    return 0;
}
