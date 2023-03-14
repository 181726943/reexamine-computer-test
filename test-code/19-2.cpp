#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    string str;  //str用于存储文件
    char ch;
    int line = 1;  //line表示行号
    bool flag = true;
    //读文件
    ifstream infile("D:\\Desktop\\reexamine\\C_exam\\abc.cpp");
    infile>>noskipws;
    if(infile.is_open()) {
        /* *
         * 这种写法有个问题
         * 在读到文件结尾时会将结尾字符连续输出两次
         * 原因是get()函数在读取到终止标志字符时指针不移动，会停留在原位置
         * 下次读取时仍然会从该位置读取
         * */
//        while (!infile.eof()) {
//            infile.get(ch);
//            str.push_back(ch);
//        }
        while (infile.get(ch)) {
            str.push_back(ch);
        }
    }
    else
        cerr<<"open error!"<<endl;
    infile.close();

    //处理文件
    string::size_type front, rear;
    int count = 0;
    while(flag){
        count = 0;  //记录“//”型注释包含的字符数
        if((front = str.find("//",0)) == string::npos && (front = str.find("/*",0)) == string::npos)
            flag = false;
        else if((front = str.find("//",0)) == string::npos && (front = str.find("/*",0)) != string::npos){
            rear = str.find("*/",0);
            count = rear - front + 3;
            str.erase(front,count);
        }
        else if((front = str.find("//",0)) != string::npos){
            for(int i = front; str[i] != '\n'; i++){
                ++count;
            }
            str.erase(front,count);
        }
    }

    //输出行号以及文件内容
    cout<<left<<setw(4)<<(line++);
    for(decltype(str.size()) i = 0; i < str.size(); i++){
        //处理空行，空行也要输出行号
        while(str[i] == '\n' && i != str.size()-1){
            ++i;
            cout<<endl;
            cout<<left<<setw(4)<<(line++);
        }
        cout<<str[i];
    }
    cout<<endl;
    system("pause");
    return 0;
}
