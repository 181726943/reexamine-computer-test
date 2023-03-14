#include <iostream>
#include <cstdlib>

using namespace std;

//判定是否是闰年
bool isleap(short);

int main(){
    system("chcp 65001");  //这里用vscode调用外部控制台，避免输出乱码(暂时更改)，仅对本程序有效
    short year, month, day;
    short monday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    short dates;
    cout<<"请输入日期: ";
    cin>>year>>month>>day;
    //判断年份以及月份是否合法
    if(year < 2000 || year > 2099 || month > 12 || month < 1){
        cout<<"input error!"<<endl;
        exit(-1);
    }
    //判断日期是否合法
    if(isleap(year)) monday[2] += 1;  //如果是闰年，2月多一天
    if(day > monday[month]){
        day = monday[month];
    }
    year = year % 100;
    year = (year & 0x007f) << 9;
    month = (month & 0x000f) << 5;
    day = day & 0x001f;
    dates = year | month | day;
    cout<<"压缩后的日期为: "<<dates<<endl;

    system("pause");
    return 0;
}

bool isleap(short year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}