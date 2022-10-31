// https://www.acmicpc.net/problem/9095
#include <iostream>
using namespace std;

// 정수 n이 주어진다. n은 양수이며 11보다 작다.
int arr[11];

// Q. 팩토리얼 때문에 dp로 배치한거임?
int f(int n) {
    if (n==0) arr[0]=1;
    if (arr[n] != 0) return arr[n];
    return arr[n] = n*f(n-1);
}

int main() {
    int T,n,cnt=0;
    cin>>T;
    while(T--) {
        cin>>n;
        for (int a=n/3; a>=0; --a) {
            for (int b=(n-3*a)/2; b>=0; --b) {
                // Q. 중복순열로 하는 거 맞음?
                int c = n - 3*a - 2*b;
                cnt += f(a+b+c)/(f(a)*f(b)*f(c));
            }
        }
        cout<<cnt<<'\n';
        cnt=0;
    }
}