// https://www.acmicpc.net/problem/1193
#include <iostream>
using namespace std;

int main() {
    int X,q,p;
    cin>>X;
    
    int n=1;
    for(;;++n) {
        int num = (n*(n+1))/2;
        if (X<=num) break;
    }
    
    int start = (n*(n-1))/2 +1;
    int diff = X - start;
    
    if(n%2==0) {
        q=1, p=n;
        cout<<q+diff<<'/'<<p-diff;
    } 
    else {
        q=n, p=1;
        cout<<q-diff<<'/'<<p+diff;
    }
}