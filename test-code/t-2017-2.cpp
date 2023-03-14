#include "iostream"
#include "string"

using namespace std;

int main(){
	string s, res;
	int n = 0;
	cout<<"ÇëÊäÈë×Ö·û´®:";
	cin>>s;
	if(s.size() % 2 == 1){
		s.insert(s.size(), 1, '0');
	}
	for(decltype(s.size()) i = 0; i < s.size(); i += 2){
		char ch = 10 * (int(s[i]) - (int)'0') + ((int)s[i+1] - (int)'0') + 32;
		res.append(1, ch);
	}
	cout<<res;
	return 0;
}
