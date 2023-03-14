#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

int main(){
    int num;
    vector<int> arr;
    //����������
    while(cin>>num)
        arr.push_back(num);
    for(auto it = arr.begin(); it != arr.end(); it++)
        cout<<*it<<' ';
    cout<<endl;

    //�������
    sort(arr.begin(), arr.end(),less<int>());
    for(auto it = arr.begin(); it != arr.end(); it++)
        cout<<(*it)<<' ';
    vector<int>().swap(arr);

    return 0;
}
