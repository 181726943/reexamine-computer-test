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
	 cout<<"ƽ����Ϊ��"<<fixed<<setprecision(1)<<sum<<endl;  //����fixed��setprecision��ʾС������λ��,���ӱ�ʾ��Ч����λ��
 	return 0;
 } 
