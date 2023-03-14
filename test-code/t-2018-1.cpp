#include <iostream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

int main(){
    string s;
    map<char,int>cmap;  //记录英文句子中每个字母出现的次数
    int alpha = 0,word = 0;  //alpha--字母个数,word--单词个数
    string amax;  //记录出现次数最多的字母
    int times = 0;  //记录出现次数最多的字母出现的次数
    cout<<"请输入英文句子: ";
    getline(cin, s);
//	cin>>noskipws;  //设置cin读取空格
//	cin>>s;
    for(auto ch : s){
        if(isalpha(ch))
            alpha++;
        if(ch == ' ')
            word++;
        if(ch != ' ')
            cmap[tolower(ch)]++;
    }
    word++;  //通过空格个数判断单词个数，单词个数比空格个数多1
    cout<<"字母个数: "<<alpha<<endl;
    cout<<"单词个数: "<<word<<endl;
    //查找出现次数最多的元素
    for(auto it = cmap.cbegin(); it != cmap.cend(); it++){
         if(times < it->second){
            times = it->second;
         }
    }
    for(auto it = cmap.cbegin(); it != cmap.cend(); it++)
        if(it->second == times)
            amax.push_back(it->first);
    cout<<"最多的字母: ";
    for(decltype(amax.size()) i = 0; i < amax.size(); i++){
        cout<<amax[i];
        if(i != amax.size()-1){
            cout<<",";
        }
    }
    cout<<endl;
    cout<<"出现的次数: "<<times<<endl;
    system("pause");
    return 0;
}
