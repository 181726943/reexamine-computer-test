#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;  //输入实例个数
    int h1,h2,m1,m2,s1,s2;  //h=>时，m=>分，s=>秒，分别对应两组数据
    int s_in, m_in;  //秒和分的进位，满60进1
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
        s_in = (s1 + s2) / 60;
        s1 = (s1 + s2) % 60;
        m_in = (m1 + m2 + s_in) / 60;
        m1 = (m1 + m2 + s_in) % 60;
        h1 = h1 + h2 + m_in;
        printf("%d %d %d\n", h1, m1, s1);
    }
    system("pause");
    return 0;
}