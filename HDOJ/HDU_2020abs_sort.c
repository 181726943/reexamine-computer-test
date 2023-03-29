/* 
 * 输入n(n<=100)个整数，按照绝对值从大到小排序后输出。
 * 题目保证对于每一个测试实例，所有的数的绝对值都不相等。 
 */
#include <stdio.h>
#include <stdlib.h>

int partition(int[], int, int);  //划分函数
void qsort(int[], int, int);  //快排

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        int a[100];
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        qsort(a, 0, n-1);
        for(int i = 0; i < n; i++){
            if(i != 0) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}

int partition(int a[], int low, int high){  //一趟划分
    int pivot = a[low];
    while(low < high){
        while(low < high && abs(a[high]) <= abs(pivot))  //注意是绝对值排序
            high --;
        a[low] = a[high];
        while(low < high && abs(a[low]) >= abs(pivot))
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void qsort(int a[], int low, int high){  //快排
    if(low < high){
        int mid = partition(a, low, high);
        qsort(a, low, mid-1);
        qsort(a, mid+1, high);
    }
}