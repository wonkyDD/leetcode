// https://www.acmicpc.net/problem/11726
// https://kosaf04pyh.tistory.com/222
#include <iostream>
using namespace std;

// unsigned int arr[1001] = {0};
int arr[1001];

// unsigned int f(int n) {
//     if (arr[n] != 0) return arr[n];
//     return arr[n] = f(n-1) + f(n-2);
// }
int f(int n) {
    if (arr[n] != 0 ) return arr[n];
    return arr[n] = (f(n-1) + f(n-2))%10007;
}

int main() {
    int n;
    cin>>n;
    
    // arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    
    // cout<<f(n)%10007;
    cout<<f(n);
}