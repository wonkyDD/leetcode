// https://www.acmicpc.net/problem/3052
#include <iostream>
using namespace std;

int main() {
    int num, cnt=0;
    bool rem[42] = {false};
    for(int i=0; i<10; ++i) {
        cin>>num;
        if(rem[num%42] == false) rem[num%42]=true, ++cnt;
    }
    
    cout<<cnt;
}