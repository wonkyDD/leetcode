// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution
{
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
} // namespace Solution

namespace Fail2
{
int main()
{
    int N,M,num;
    vector<int> n;
    vector<pair<int,int> > m;

    cin>>N;
    n.reserve(N);
    for (int i=0; i<N; ++i)
    {
        cin>>num;
        n.push_back(num);
    }

    cin>>M;
    m.reserve(M);
    for (int i=0; i<M; ++i)
    {
        cin>>num;
        m.push_back(make_pair(num, 0));
    }

    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
            if (m[j].first == n[i]) m[j].second += 1;
    }
    
    for (int i=0; i<M; ++i) cout<<m[i].second<<' ';
}
} // namespace Fail2

namespace Fail1
{
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
} // namespace Fail1
