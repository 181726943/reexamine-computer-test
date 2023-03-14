#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "cstring"
using namespace std;

int main(){
    FILE *fp, *fp1;  //文件指针
    if((fp = fopen("D:\\abc0.txt","w")) == NULL){
        cout<<"con't open the file!"<<endl;
        exit(0);
    }

    //1.键盘输入创建文件
    char ch;
    while((ch = getchar()) != EOF)
        fputc(ch, fp);
    fclose(fp);

    //2.文件输入处理与输出
    if((fp = fopen("D:\\abc0.txt", "r")) == NULL){
        cout<<"con't open the file"<<endl;
        exit(0);
    }
    if((fp1 = fopen("D:\\abc1.txt", "w")) == NULL){
        cout<<"con't open the file!"<<endl;
        exit(0);
    }
    bool flag = false;  //false表示空格还未添加到新文件，true表示空格已添加到新文件
    //while循环处理文件
    while((ch = fgetc(fp)) != EOF){
        if(ch == ' '){
            if(flag) continue;  //空格已处理过，
            cout<<ch; //输出处理后的文本
            fputc(ch, fp1);  //输出到新文件
            flag = true;
        }
        else{
            cout<<ch;
            fputc(ch, fp1);
            flag = false;
        }
    }
    fclose(fp);
    fclose(fp1);

    //3.统计字符、单词、句子个数
    if((fp1 = fopen("D:\\abc1.txt", "r")) == NULL){
        cout<<"con't open the file!"<<endl;
        exit(0);
    }
    int ch_num = 0;  //记录字符个数
    int wo_num = 0;  //记录单词个数
    int se_num = 0;  //记录句子个数
    while((ch = fgetc(fp)) != EOF){
        ch_num++;
        if(ch == ' ' || ch == ',' || ch == ';' || ch == '.' || ch == '!' || ch == '?')
            wo_num++;
        if(ch == '.' || ch == '!' || ch == '?')
            se_num++;
    }
    cout<<"字符个数: "<<ch_num<<" 单词个数: "<<wo_num<<" 句子个数: "<<se_num<<endl;
    fclose(fp1);

    return 0;
}
