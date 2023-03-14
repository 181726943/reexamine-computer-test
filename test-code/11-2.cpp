#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

int main(){
    int num;
    vector<int> arr;
    //无冗余输入
    while(cin>>num)
        arr.push_back(num);
    for(auto it = arr.begin(); it != arr.end(); it++)
        cout<<*it<<' ';
    cout<<endl;

    //排序并输出
    sort(arr.begin(), arr.end(),less<int>());
    for(auto it = arr.begin(); it != arr.end(); it++)
        cout<<(*it)<<' ';
    vector<int>().swap(arr);

    return 0;
}
