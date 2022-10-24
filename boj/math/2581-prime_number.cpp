// https://www.acmicpc.net/problem/2581
#include <iostream>
using namespace std;

int main() {
    int N, M, sum=0, min=0;
    cin>>M>>N;
    
    for(int num=M; num<=N; ++num) {
        int i=2;
        for(; i<num; ++i) {
            if (num%i==0) break;
        }
        
        if (i==num) {
            sum+=num;
            if (min==0) min=num;
        }
    }
    
    if (min==0) cout<<-1;
    else cout<<sum<<endl<<min;
}
