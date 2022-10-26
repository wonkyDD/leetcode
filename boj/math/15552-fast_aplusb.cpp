// https://www.acmicpc.net/problem/15552
#include <iostream>
using namespace std;

int main() {
    int T,a,b;
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>T;
    for (int i=0; i<T; ++i) {
        cin>>a>>b;
        cout<<a+b<<"\n";
    }
}