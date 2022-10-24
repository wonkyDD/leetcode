// https://www.acmicpc.net/problem/8958
#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; ++i) {
        string s;
        cin>>s;
        
        int sum=0, extra=0;
        char before = ' ';
        for(auto it=s.begin(); it!=s.end(); ++it) {
            char c = *it;
            if (c=='O') {
                extra = before==c ? extra+1 : extra;
                before='O';
                sum += extra+1;
            }
            else {
                before='X';
                extra = 0;
            }
        }
        cout<<sum<<endl;
    }
}
