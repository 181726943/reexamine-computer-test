#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const string spech = "~!@#$%^";

int main(){
    int M;  //测试实例个数
    string pwd;  //密码
    int type_count;  //密码所包含的类型数
    /* 
     * flag_up : 密码中是否存在大写字母
     * flag_lw : 密码中是否存在小写字母
     * flag_nm : 密码中是否存在数字
     * flag_sc : 密码中是否存在特殊字符
     */
    bool flag_up, flag_lw, flag_nm, flag_sc;
    cin>>M;
    for(int i = 0; i < M; i++){
        cin>>pwd;
        //不符合长度要求，输出NO且直接进入下次循环
        if(pwd.size() < 8 || pwd.size() > 16){
            cout<<"NO"<<endl;
            continue;
        }else{  //符合长度要求
            type_count = 0;
            flag_up = false, flag_lw = false, flag_nm = false, flag_sc = false;
            for(auto it = pwd.cbegin(); it != pwd.cend(); it++){
                if(!flag_up && isupper(*it))
                    flag_up = true;
                if(!flag_lw && islower(*it))
                    flag_lw = true;
                if(!flag_nm && isdigit(*it))
                    flag_nm = true;
                if(!flag_sc && spech.find(*it, 0) != string::npos)
                    flag_sc = true;
            }
            type_count = flag_up + flag_lw + flag_nm + flag_sc;
            if(type_count >= 3){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}