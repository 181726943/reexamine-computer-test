#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>&, vector<int>&, int, int);  //快排的一趟划分
void quicksort(vector<int>&, vector<int>&, int, int);  //快排

int main(){
    int n;
    int beg, over;  //处理输入，表示每个节目的开始结束时间
    int time, count;  //time用于记录节目结束时间，count表示可看节目数
    while(cin>>n && n){
        //start存放开始时间，end存放结束时间
        vector<int> start, t_end;
        for(int i = 0; i < n; i++){
            cin>>beg>>over;
            start.push_back(beg);
            t_end.push_back(over);
        }
        quicksort(t_end, start, 0, start.size()-1);
        time = t_end[0];
        count = 1;
        for(int i = 1; i < t_end.size(); i++){
            if(time <= start[i]){
                time = t_end[i];
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

int partition(vector<int> &a, vector<int> &b, int low, int high){
    int pivot = a[low];
    int temp = b[low];
    while(low < high){
        while(a[high] >= pivot && low < high)
            high--;
        //两个vector中的数据同步交换
        a[low] = a[high];
        b[low] = b[high];
        while(a[low] <= pivot && low < high)
            low++;
        a[high] = a[low];
        b[high] = b[low];
    }
    a[low] = pivot;
    b[low] = temp; 
    return low;
}

void quicksort(vector<int> &a, vector<int> &b, int low, int high){
    int mid = partition(a, b, low, high);
    if(low < high){
        quicksort(a, b, low, mid-1);
        quicksort(a, b, mid+1, high);
    }
}