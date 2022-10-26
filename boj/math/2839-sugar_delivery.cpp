// https://www.acmicpc.net/problem/2839
#include <iostream>
using namespace std;

int main() {
    int N, q, r;
    cin>>N;
    q=N/5, r=N%5;
    if (r==0) cout<<q;
    else {
        int i;
        for(i=0; i<=q; ++i, r+=5) {
            if (r%3==0) {
                cout<< (r/3) + (q-i);
                break;
            }
        }
        if (i>q) cout<<-1;
    }
}

// int main() {
//     int N, q, r;
//     cin>>N;
//     q=N/5, r=N%5;
//     if (r==0) cout<<q;
//     else {
//         int i;
//         for(i=0; i<q; ++i) {
//             r += 5;
//             if (r%3==0) {
//                 cout<< (r/3) + (q-i-1);
//                 break;
//             }
//         }
//         if (i==q) cout<<-1;
//     }
// }