#include "iostream"
#include "string"
#include "cctype"

using namespace std;

int main(){
    string s;
    cout<<"请输入字符串: ";
    getline(cin,s);
    bool flag = false;  //标记字符串前面是否是空格
    int count = 0;  //记录字符串首部空格个数
    //去除字符串首部空格
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
//    cout<<"去除首部空格后的字符串: "<<s<<endl;
    //处理中间空格
    //flag=false表示前一个字符非空格，flag=true表示前面已有空格
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

    //在数字和字母之间加上_
    for(int i = 0; i < s.size(); i++){
        if((isdigit(s[i]) && isalpha(s[i+1])) || (isalpha(s[i]) && isdigit(s[i+1]))){
            s.insert(i+1, 1, '_');
        }
    }
    cout<<"处理之后的字符串: "<<s<<endl;

    return 0;
}
