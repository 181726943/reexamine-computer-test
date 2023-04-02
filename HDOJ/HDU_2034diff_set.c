#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int comp(const void*, const void*);  //qsort函数的比较函数
bool search(int[], int, int);  //查找函数, 参数1=查找数组, x=带查找元素, n=数组中元素个数

int main(){
    int n, m;  //两个集合元素个数
    int a[100] = {0};
    int b[100] = {0};
    int count = 0;
    while(scanf("%d %d", &n, &m) != EOF &&(n || m)){
        count = 0;
        memset(a, 0, sizeof(a));  //将a中所有元素初始化为0
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), comp);
        for(int i = 0; i < m; i++){
            scanf("%d", &b[i]);
        }
        qsort(b, m, sizeof(int), comp);
        for(int k = 0; k < n; k++){
            if(!search(b, a[k], m)){
                printf("%d ", a[k]);
                ++count;  //差集元素个数+1
            }
        }
        if(count == 0)
            printf("NULL");
        printf("\n");
    }
    return 0;
}

int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

bool search(int a[], int x, int n){  //二分查找
    int high, low, mid;
    high = n-1;
    low = 0;
    while(low <= high){
        mid = (low + high) / 2;
        if(a[mid] == x){
            return true;
        }  
        else if(a[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}