#include "iostream"
#include "cstring"
#include "string"

using namespace std;

int main(){
    string tel;
    cout<<"ÇëÊäÈëµç»°ºÅÂë: ";
    cin>>tel;
    bool res = true;
    if(tel.size() != 11 || tel[0] != '1' || (tel[1] != '3' && tel[1] != '5' && tel[1] != '8' && tel[1] != '6')){
        res = false;
    }
    for(auto c : tel )
        if(!isdigit(c)){
            res = false;
            break;
        }
    if(res)
        cout<<"true!"<<endl;
    else
        cout<<"error!"<<endl;
    return 0;
}
