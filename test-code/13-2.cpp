#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "vector"


using namespace std;

int main(){
    int n;
    cout<<"�����뷽�����n: ";
    cin>>n;
    vector<vector<int> >matrix(n, vector<int>(n));   //�ö�ά����ģ�����
    int length;  //ÿһ�㷽��߳�
    int x, y;  //(x,y)Ϊ��������
    int num = 1;  //��¼������ÿһ��λ�ô�ŵ�����
    for(length = n, x = 0, y = 0; length > 0; length -= 2, ++x, ++y){
        //x,yΪ�������
        //����һ���߳�Ϊlength��������
        //ͬʱҪ��֤˳ʱ����ת��ȷ��ÿ��λ�õ�������ȷ
        int i = x, j = y;
        //i���䣬j��y��y+length-1 ��
        for(; j < y+length; j++) matrix[i][j] = num++;
        //j���䣬i��x��x+length-1 ��
        for(j--, i++; i < x+length; i++) matrix[i][j] = num++;
        //��
        for(i--, j--; j >= y; j--) matrix[i][j] = num++;
        //��
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
