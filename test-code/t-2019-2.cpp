#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    string str;  //str���ڴ洢�ļ�
    char ch;
    int line = 1;  //line��ʾ�к�
    bool flag = true;
    //���ļ�
    ifstream infile("D:\\Desktop\\reexamine\\C_exam\\abc.cpp");
    infile>>noskipws;
    if(infile.is_open()) {
        /* *
         * ����д���и�����
         * �ڶ����ļ���βʱ�Ὣ��β�ַ������������
         * ԭ����get()�����ڶ�ȡ����ֹ��־�ַ�ʱָ�벻�ƶ�����ͣ����ԭλ��
         * �´ζ�ȡʱ��Ȼ��Ӹ�λ�ö�ȡ
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

    //�����ļ�
    string::size_type front, rear;
    int count = 0;
    while(flag){
        count = 0;  //��¼��//����ע�Ͱ������ַ���
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

    //����к��Լ��ļ�����
    cout<<left<<setw(4)<<(line++);
    for(decltype(str.size()) i = 0; i < str.size(); i++){
        //������У�����ҲҪ����к�
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
