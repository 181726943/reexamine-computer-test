#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "cstring"
using namespace std;

int main(){
    FILE *fp, *fp1;  //�ļ�ָ��
    if((fp = fopen("D:\\abc0.txt","w")) == NULL){
        cout<<"con't open the file!"<<endl;
        exit(0);
    }

    //1.�������봴���ļ�
    char ch;
    while((ch = getchar()) != EOF)
        fputc(ch, fp);
    fclose(fp);

    //2.�ļ����봦�������
    if((fp = fopen("D:\\abc0.txt", "r")) == NULL){
        cout<<"con't open the file"<<endl;
        exit(0);
    }
    if((fp1 = fopen("D:\\abc1.txt", "w")) == NULL){
        cout<<"con't open the file!"<<endl;
        exit(0);
    }
    bool flag = false;  //false��ʾ�ո�δ��ӵ����ļ���true��ʾ�ո�����ӵ����ļ�
    //whileѭ�������ļ�
    while((ch = fgetc(fp)) != EOF){
        if(ch == ' '){
            if(flag) continue;  //�ո��Ѵ������
            cout<<ch; //����������ı�
            fputc(ch, fp1);  //��������ļ�
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

    //3.ͳ���ַ������ʡ����Ӹ���
    if((fp1 = fopen("D:\\abc1.txt", "r")) == NULL){
        cout<<"con't open the file!"<<endl;
        exit(0);
    }
    int ch_num = 0;  //��¼�ַ�����
    int wo_num = 0;  //��¼���ʸ���
    int se_num = 0;  //��¼���Ӹ���
    while((ch = fgetc(fp)) != EOF){
        ch_num++;
        if(ch == ' ' || ch == ',' || ch == ';' || ch == '.' || ch == '!' || ch == '?')
            wo_num++;
        if(ch == '.' || ch == '!' || ch == '?')
            se_num++;
    }
    cout<<"�ַ�����: "<<ch_num<<" ���ʸ���: "<<wo_num<<" ���Ӹ���: "<<se_num<<endl;
    fclose(fp1);

    return 0;
}
