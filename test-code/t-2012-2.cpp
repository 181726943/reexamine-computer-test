#include "iostream"
#include "cctype"
#include "vector"
#include "cstdlib"
#include "cstring"
#include "string"

using namespace std;

bool check_in(string s){  //�������
    for(decltype(s.size()) index = 0; index < s.size();index++){
        if(isalpha(s[index]) != isalpha(s[0]) || isdigit(s[index]) != isdigit(s[0]) || (!isalpha(s[0]) && !isdigit(s[0])))
            return false;
    }
    return true;
}

int main(){
    vector<string> arr_s;
    string s;
    cout<<"������n���ַ���(��#����): "<<endl;
    while(cin>>s && s != "#"){
        if(check_in(s)){
            arr_s.push_back(s);
        }else{
            cout<<"���벻�Ϸ�"<<endl;
            exit(0);
        }
    }
    cout<<"����ǰ�������:"<<endl;
    for(int index = arr_s.size()-1; index >= 0; index--)
        cout<<arr_s[index]<<' ';
    cout<<endl;

    //�������
    for(int index = 0; index < arr_s.size(); index++){
        for(int k = index+1; k < arr_s.size(); k++)
            if(isdigit(arr_s[index][0]) && isdigit(arr_s[k][0])){
                int first = stoi(arr_s[index]);
                int second = stoi(arr_s[k]);
                if(first < second) continue;
                string temp =arr_s[k];
                arr_s[k] = arr_s[index];
                arr_s[index] = temp;

            }
            else if(arr_s[index].compare(arr_s[k]) > 0){
                string temp =arr_s[k];
                arr_s[k] = arr_s[index];
                arr_s[index] = temp;
            }
    }
    cout<<"������������:"<<endl;
    for(auto it = arr_s.begin(); it != arr_s.end(); it++)
        cout<<*it<<' ';
    cout<<endl;
//    arr_s.clear();
    vector<string>().swap(arr_s);  //�ͷſռ�
//    cout<<"arr_s.size():"<<arr_s.size()<<endl;
//    cout<<"arr_s.capcity():"<<arr_s.capacity()<<endl;


    return 0;
}
