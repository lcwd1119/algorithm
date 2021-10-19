#include <iostream>
using namespace std;

void find_seq(int len,string str,int onesleft){
    if(str.size() != len) {
        find_seq(len, str + "0", onesleft);
        if (onesleft > 0)
            find_seq(len, str + "1", onesleft - 1);
        return;
    }
    if(onesleft == 0)
        cout << str << endl;
    return;
}

int main(){
    int times;
    cin>>times;
    for(int i = 0;i < times;i++){
        if(i != 0)
            cout << endl;
        int len,ones;
        cin >> len >> ones;
        find_seq(len,"0",ones);
        if(ones > 0)
            find_seq(len,"1",ones - 1);
    }
    return 0;
}