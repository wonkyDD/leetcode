// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int N,M,num;
    unordered_map<int, int> n;
    vector<int> m;

    cin>>N;
    n.reserve(N);
    for (int i=0; i<N; ++i)
    {
        cin>>num;
        if (n.find(num) != n.end()) n[num] += 1;
        else n.insert(make_pair(num, 1));
    }

    cin>>M;
    m.reserve(M);
    for (int i=0; i<M; ++i)
    {
        cin>>num;
        m.push_back(num);
    }

    for (int i=0; i<M; ++i)
    {
        if (n.find(m[i]) != n.end()) cout<<n[m[i]]<<' ';
        else cout<<'0'<<' ';
    }
}