// https://www.acmicpc.net/problem/1546
// https://st-lab.tistory.com/273
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; 
    double num, max=0, sum=0;
    vector<double> v;
    cin>>N;
    for (int i=0; i<N; ++i) {
        cin>>num;
        v.push_back(num);
    }
    for (int i; i<v.size(); ++i) {
        max = v[i] > max? v[i] : max;
        sum += v[i];
    }
    
    double q=sum*100, p=v.size()*max;
    cout<<q/p;
}

// int main() {
//     int N, num, max=0, sum=0;
//     vector<int> v;
//     cin>>N;
//     for (int i; i<N; ++i) {
//         cin>>num;
//         v.push_back(num);
//     }
//     // 평균구하기(오차 .01 이하)
//     for (int i; i<v.size(); ++i) {
//         max = v[i] > max? v[i] : max;
//         sum += v[i];
//     }
    
//     double q=sum*100, p=v.size()*max;
//     cout << fixed;
//     cout.precision(20);
//     cout<<q/p;
// }