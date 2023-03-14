#include "cstdio"
#include "iostream"

using namespace std;

typedef unsigned long ul;

void printul(ul num){
    int buf[32];
    int counts = 0;
    int radix = 2;
    while(num > 0){
        buf[counts++] = num % radix;
        num /= radix;
    }
    counts = 0;
    for(int i = 31; i >= 0; i--){
        cout<<buf[i];
        counts++;
        if(counts % 8 == 0)
            cout<<' ';
    }
}

int main(){
    ul num, high, low, mid;
    cout<<"�������޷��ų�����: ";
    cin>>num;
    //�����������ֽ�
    high = num >> 24;  //����ǰ�ĸ��ֽ�
    low = num << 24;  //����ǰ�ĵ��ֽ�
    num = num & 0x00ffff00;
    num = num | high | low;
    printul(num);
    cout<<endl;

    //ѭ������nλ
    int n;
    cout<<"����������λ��: ";
    cin>>n;
    n = n % 16;
    mid = num & 0x00ffff00;  //ȡ�м������ֽ�
    mid = mid >> 8;
    mid = mid << n;
    low = mid >> 16;
    high = mid & 0x0000ffff;
    mid = (low | high) << 8;
    low = num & 0x000000ff;
    high = num & 0xff000000;
    num = low | high | mid;
    printul(num);

    return 0;
}
