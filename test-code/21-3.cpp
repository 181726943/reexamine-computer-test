#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeKdigits1(string, int);
string removeKdigits2(string, int);

int main(){
    system("chcp 65001");
    string num;
    int k;
    cout<<"请输入数字字符串:";
    cin>>num;
    cout<<ends;
    cout<<"请输入要删除的数字个数:";
    cin>>k;
    string res = removeKdigits1(num, k);
    cout<<"结果为: "<<res<<endl;

    system("pause");
    return 0;
}

//这种筛选方法可保证时间复杂度不会很高 O(n)
string removeKdigits1(string num, int k){
    vector<char> selector;
    for(auto digit : num){
        while(!selector.empty() && selector.back() > digit && k){
            selector.pop_back();
            --k;
        }
        selector.push_back(digit);
    }
    while(k--){
        selector.pop_back();
    }
    string res = "";
    bool isLead0 = true;
    for(auto it : selector){
        if(isLead0 && it == '0'){
            continue;
        }
        isLead0 = false;
        res += it;
    }
    return res == "" ? "0" : res;
}

//这种筛选方法时间复杂度高
string removeKdigits2(string num, int k) {
    int minc = 0;  //minc用于定位前k...num.size()中最小的数字下标
    string res;  //存储结果
    int len = num.size() - k;  //最小数的位数
    int i = minc, j;
    if(num.size() > k)
        while(len > 0){
            --len;

            for(j = i; j <= k; j++){
                if(num[minc] > num[j]){
                    minc = j;
                }
            }
            res.push_back(num[minc]);
            ++k;
            ++minc;
            i = minc;
        }
    else{
        res.push_back('0');
        return res;
    }
    //处理前导0
    while(res[0] == '0' && res.size() != 1){
        res.erase(0,1);
    }
    return res;
}