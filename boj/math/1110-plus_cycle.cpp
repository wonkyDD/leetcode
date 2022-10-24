// https://www.acmicpc.net/problem/1110
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int cycle=0;
    for (int i=n;; ++cycle) {
        int d1=i/10, d2=i%10;
        int s1=(d1+d2)/10, s2=(d1+d2)%10;
        i = 10*d2 + s2;
        
        if (i==n) break;
    }
    cout<<cycle+1;
}
