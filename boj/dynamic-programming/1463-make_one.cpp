// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {    
    int N;
    vector<int> v;
    unordered_map<int, int> p;

    cin>>N;
    v.reserve(3);
    p.reserve(N);
    
    p.insert(make_pair(1, 0));
    p.insert(make_pair(2, 1));
    p.insert(make_pair(3, 1));
    for (int i=4; i<=N; ++i) {
        v.clear();

        if (i%3==0) v.push_back(i/3);
        if (i%2==0) v.push_back(i/2);
        v.push_back(i-1);
        
        for (int j=0; j<v.size(); ++j) v[j] = 1+p[v[j]];
        sort(v.begin(), v.end());
        p.insert(make_pair(i, v[0]));
    }

    cout<<p[N];
}