/* 
 * 说明：
 * 1.oj中用递归地方法会超时，所以route函数不能用
 * 2.关于结果，结果可能会非常大，超出int类型所能表示的范围，因此用int类型存放结果会出现Wrong Answer
 *   要用long long型存放结果
*/

#include <iostream>

using namespace std;

int route(int, int);

int main(){
    int N;  //测试实例个数
    int a, b;  //起点a终点b
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>a>>b;
        long long old = 0, news = 1;
        for(int i = a+1; i <= b; i++){
            news += old;
            old = news - old;
        }
        cout<<news<<endl;
    }
    return 0;
}

int route(int a, int b){
    if(a == b)
        return 0;
    else if(a == b-1)
        return 1;
    else if(a == b-2)
        return 2;
    else
        return route(a, b-1) + route(a, b-2);
}