#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "vector"


using namespace std;

int main(){
    int n;
    cout<<"请输入方阵阶数n: ";
    cin>>n;
    vector<vector<int> >matrix(n, vector<int>(n));   //用二维数组模拟矩阵
    int length;  //每一层方阵边长
    int x, y;  //(x,y)为矩阵坐标
    int num = 1;  //记录方阵中每一个位置存放的数字
    for(length = n, x = 0, y = 0; length > 0; length -= 2, ++x, ++y){
        //x,y为起点坐标
        //填满一个边长为length的正方形
        //同时要保证顺时针旋转，确保每个位置的数字正确
        int i = x, j = y;
        //i不变，j从y到y+length-1 上
        for(; j < y+length; j++) matrix[i][j] = num++;
        //j不变，i从x到x+length-1 右
        for(j--, i++; i < x+length; i++) matrix[i][j] = num++;
        //下
        for(i--, j--; j >= y; j--) matrix[i][j] = num++;
        //左
        for(j++, i--; i > x; i--) matrix[i][j] = num++;
    }
    for(x = 0; x < n; x++){
        for(y = 0; y < n; y++)
            printf("%3d",matrix[x][y]);
        cout<<endl;
    }
    vector<int>().swap(matrix);

    return 0;
}
