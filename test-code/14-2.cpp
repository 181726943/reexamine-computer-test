#include "cstdio"
#include "iostream"

using namespace std;

//二进制输入
short getn(){
    char ch;
    short sum = 0;
    while((ch = getchar()) != ' '){
        sum = sum * 2 + (ch - '0');
    }
    return sum;
}

void print(short num){  //输出二进制
    int counts = 16;
    int res[16] = {0};
    while(num){
        res[--counts] = num % 2;
        num /= 2;
    }
    while(counts < 16){
        cout<<res[counts++];
    }
    cout<<endl;
}

int main(){
    short m, n, result;
    m = getn();
    n = getn();
    char ch = getchar();
    switch(ch){
        case '+':
            result = m + n;
            break;
        case '-':
            result = m - n;
            break;
        case '*':
            result = m * n;
            break;
        case '/':
            result = m / m;
            break;
    }
    print(result);
    return 0;
}
