// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int N,M,num;
    vector<int> n;
    unordered_map<int, int> um;

    cin>>N;
    n.reserve(N);
    for (int i=0; i<N; ++i)
    {
        cin>>num;
        n.push_back(num);
    }

    cin>>M;
    um.reserve(M);
    for (int i=0; i<M; ++i) 
    {
        cin>>num;
        if (um.find(num) == um.end())
            um.insert(make_pair(num, 0));
    }

    for (auto it=um.cbegin(); it!=um.cend(); ++it) cout<<it->first<<' '<<it->second<<'\n';

    for (int i=0; i<n.size(); ++i)
        if (um.find(n[i]) != um.end()) um[n[i]] += 1;

    for (auto it=um.cbegin(); it!=um.cend(); ++it) cout<<it->second<<' ';
}