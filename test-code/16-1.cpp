 #include "iostream"
 #include "iomanip"
 
 using namespace std;
 
 int main(){
 	double score[7];
 	double max = 0, min = 0, sum = 0;
 	for(int i = 0; i < 7; i++){
 		cin>>score[i];
 		if(min > score[i])
 			min = score[i];
 		if(max < score[i])
 			max = score[i];
 		sum += score[i];
	 }
	 sum = (sum - min - max) / 5;
	 cout<<"平均分为："<<fixed<<setprecision(1)<<sum<<endl;  //加上fixed的setprecision表示小数点后的位数,不加表示有效数字位数
 	return 0;
 } 
