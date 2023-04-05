#include <iostream>

using namespace std;

// int floor(int);  //上第i阶楼梯的走法

int main(){
    int n;
    int stair;  //存储目标阶梯数
    int method[41] = {0};
    cin>>n;
    //计算走上第i阶楼梯的方法
    for(int k = 0; k < 41; k++){
        method[0] = 0;
        if(k <= 3)
            method[k] = k - 1;
        else
            method[k] = method[k-1] + method[k-2];
    }
    for(int i = 0; i < n; i++){
        cin>>stair;
        // cout<<floor(stair)<<endl;
        cout<<method[stair]<<endl;
    }
    return 0;
}

// int floor(int num){
//     if(num <= 3)
//         return num-1;
//     else
//         return floor(num-1) + floor(num-2);
// }