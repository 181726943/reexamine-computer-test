#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void square1(int);

int main(){
    int n;
    double square = 0;  //面积
    //posx,posy记录起点坐标，是定点
    int posx, posx1, posy, posy1, posx2, posy2;  
    while(cin>>n && n){
        square = 0;
        cin>>posx>>posy;
        posx1 = posx;
        posy1 = posy;
        for(int i = 1; i < n; i++){
            cin>>posx2>>posy2;
            square += (double)(posx1 * posy2 - posx2 * posy1) * 0.5;
            if(i == n-1){
                square += (double)(posx2 * posy - posx * posy2) * 0.5;
            }
            posx1 = posx2;
            posy1 = posy2;
        }
        cout<<fixed<<setprecision(1)<<square<<endl;
    }
    return 0;
}


//这种方法只适合计算凸多边形面积
void square1(int n){
    double square = 0;  //面积
    int posx, posx1, posy, posy1;  //表示两个点的坐标
    int vecx1, vecy1, vecx2, vecy2;  //表示同一顶点出发的两个向量
    while(cin>>n && n){
        square = 0;
        cin>>posx>>posy;  //输入起点坐标，起点坐标不变
        cin>>posx1>>posy1;  //输入第二个点
        //计算第一个向量
        vecx1 = posx1 - posx;
        vecy1 = posy1 - posy;

        for(int i = 2; i < n; i++){
            vecx2 = vecx1;
            vecy2 = vecy1;
            cin>>posx1>>posy1;
            vecx1 = posx1 - posx;
            vecy1 = posy1 - posy;
            square += fabs((double)(vecy2 * vecx1 - vecx2 * vecy1) / 2.0);
        }
        cout<<fixed<<setprecision(1)<<square<<endl;
    }
}