// https://www.acmicpc.net/problem/2577
#include <iostream>
#include <map>
using namespace std;

int main() {
    int a,b,c,mul,rem;
    map<int, int> m;
    for(int i=0; i<10; ++i)
        m[i]=0;
    cin>>a>>b>>c;
    mul=a*b*c;
    while (true) {
        rem = mul%10;
        m[rem] +=1;
        if (mul/10==0) break;
        else mul /= 10;
    }    
    
    for(auto it=m.begin(); it!=m.end(); ++it) {
        cout<<it->second<<endl;
    }
}
