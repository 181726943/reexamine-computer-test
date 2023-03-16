#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int prior(string);   //判断运算符优先级
string intoRPN(string);  //将中缀表达式转化为后缀表达式(又称 逆波兰表达式)
void operation(vector<int>&);  //运算函数
int evaluate(string);  //后缀求值

int main(){
//    system("chcp 65001");
    string exp, rpn;
    int res;
    cout<<"请输入你的表达式: ";
    cin>>exp;
    cout<<ends;
    rpn = intoRPN(exp);
    cout<<"逆波兰表达式为: "<<rpn<<endl;
    res = evaluate(rpn);
    cout<<"表达式的值为: "<<res<<endl;
    system("pause");
    return 0;
}

int prior(string str){
    if(str == "*" || str == "/" || str == "%")
        return 4;
    else if(str == "+" || str == "-")
        return 3;
    else if(str == "<<" || str == ">>")
        return 2;
    return 0;
}

string intoRPN(string expr){
    vector<string> opstk;
    string rpn = "";
    for(decltype(expr.size()) index = 0; index < expr.size(); index++){
        string elem;
        //对移位运算符的处理
        if(expr[index] == '<' || expr[index] == '>')
            elem.push_back(expr[index++]);
        elem.push_back(expr[index]);
        //运算数直接加入后缀表达式
        if(isdigit(elem[0]) || expr[index] == '.'){
            rpn += elem;
            if(!isdigit(expr[index+1]) && expr[index+1] != '.')
                rpn += ' ';
            continue;
        }
        //遇到左括号，直接加入运算符栈
        if(elem == "("){
            opstk.push_back(elem);
            continue;
        }
        //遇到右括号则弹出左括号之前的所有运算符
        if(elem == ")"){
            while(opstk.back() != "("){
                rpn += opstk.back();  //将运算符加入后缀表达式
                rpn += ' ';
                opstk.pop_back();  //从运算符栈中弹出已加入后缀表达式的运算符
            }
            opstk.pop_back();  //将左括号弹出运算符栈，括号无需加入后缀表达式
            continue;
        }
        //将 栈中 所有优先级 高于 当前运算符 的运算符弹出
        while((!isdigit(expr[index])) && (!opstk.empty()) && opstk.back() != "(" && prior(opstk.back()) >= prior(elem)){
            rpn += opstk.back();  //高优先级运算符加入后缀表达式
            rpn += " ";   //每个运算符之间接空格，便于后续处理
            opstk.pop_back();  //弹出高优先级运算符
        }
        opstk.push_back(elem);  //当前运算符入栈
    }
    //处理剩余的运算符，将剩余运算符全部出栈加入后缀表达式
    while(!opstk.empty()){
        rpn += opstk.back();
        rpn += ' ';
        opstk.pop_back();
    }
    vector<string>().swap(opstk);  //回收运算符栈的空间
    return rpn;
}

void operation(vector<int> &rpn, char opch){
    //将栈顶的两个操作数弹出进行运算
    int a = rpn.back();
    rpn.pop_back();
    int b = rpn.back();
    rpn.pop_back();

    switch(opch){
        case '+':
            rpn.push_back(a+b);
            break;
        case '-':
            rpn.push_back(a-b);
            break;
        case '*':
            rpn.push_back(a*b);
            break;
        case '/':
            rpn.push_back(a/b);
            break;
        case '%':
            rpn.push_back(a%b);
            break;
        case '<':
            rpn.push_back(b<<a);
            break;
        case '>':
            rpn.push_back(b>>a);
            break;
        default:
            break;
    }
}

int evaluate(string rpn){
    int res;
    vector<int> operand;  //操作数栈，存放暂时未参加运算的操作数
    for(auto it = rpn.begin(); it != rpn.end(); it++){
        if(*it == ' ') continue;
        //数字直接压入运算数栈
        if(isdigit(*it)){
            int num = 0;
            while(isdigit(*it)){
                num = num * 10 + (*it - '0');
                ++it;
            }
            operand.push_back(num);
        }
        //运算符则进行运算，因为每个操作数及运算符之间有空格，因此需要排除空格
        if(!isdigit(*it) && *it != ' '){
            operation(operand,*it);
        }
    }
    res = operand.back();
    operand.pop_back();
    vector<int>().swap(operand);
    return res;
}

