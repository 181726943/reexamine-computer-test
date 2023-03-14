#include <iostream>
#include <vector>
#include <iomanip>

typedef int type;  //题目未确定卡牌类型暂定为int型，如需更改类型，只需在此处更改即可

using namespace std;

void cut(vector<type>&, int);  //切牌函数声明
void wash(vector<type>&);  //洗牌函数声明

int main(){
    system("chcp 65001");  //视编译器而定，vscode需要这行代码，否则外部控制台输出乱码(65001-->UTF-8)
    vector<type> card;
    cout<<"请输入扑克牌序列:"<<endl;
    type val;
    int n;  //切牌范围

    //输入扑克牌序列
    for(int i = 0; i < 8; i++){
        cin>>val;
        card.push_back(val);
    }

    cout<<flush;  //此处要刷新一下缓冲区，隔离前后两次输入
    
    //切牌
    cout<<"输入切牌范围: ";
    cin>>n;
    if(n < card.size()){
        for(int i = 0; i < 3; i++){
            cut(card, n);
        }
    }
    //洗牌
    wash(card);

    cout<<"切牌/洗牌后的顺序:"<<endl;
    for(auto it = card.cbegin(); it != card.cend(); it++)
        cout<<left<<setw(2)<<*it;
    cout<<endl;
    system("pause");
    return 0;
}

void cut(vector<type> &card, int n){
    /* 
     * 切牌方法一 需要额外空间
     * 申请n个辅助空间，一次将0~n拿出原牌堆
     * 然后放到剩余牌后面
     */
    vector<type> temp(card.begin(), card.begin()+n);
    card.erase(card.begin(),card.begin()+n);
    card.insert(card.end(), temp.begin(), temp.end());
    /* 
     * 切牌方法二 处理时间长 (未调试，运行结果未知)
     * 一张一张牌处理，依次放置到余牌之后
     */
    /* for(decltype(card.size()) index = 0; index <= n; index++){
        type temp = card[0];
        card.erase(card.begin());
        card.push_back(temp);
    } */
}

//洗牌
void wash(vector<type> &card){
    vector<type> temp(card.begin(), card.end());  //申请新的辅助空间
    vector<type>().swap(card);  //将原序列置空
    auto first = temp.begin();
    auto second = temp.begin() + 4;
    //按洗牌规则将牌放入原序列
    while(second != temp.end()){
        card.push_back(*first);
        card.push_back(*second);
        first++;
        second++;
    }
    vector<type>().swap(temp);  //释放辅助空间
}