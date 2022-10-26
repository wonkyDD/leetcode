// https://www.acmicpc.net/problem/10951
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a,b;
    vector<int> v;
    while (!(cin >> a >> b).eof()) {
        // cin>>a>>b;
        v.push_back(a+b);
    }
    for (auto it=v.begin(); it!=v.end(); ++it) 
        cout<<*it<<endl;
}

// int main() {
//     int a,b;
//     while (!cin.eof()) {
//         cin>>a>>b;
//     }
//     cout<<a+b;
// }
