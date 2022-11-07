// https://www.acmicpc.net/problem/1764
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N,M,cnt=0;
    string s;
    unordered_map<string, int> um;
    
    cin>>N>>M;
    for (int i=0; i<N; ++i)
    {
        cin>>s;
        um.insert(make_pair(s, 0));
    }
    for (int i=0; i<M; ++i)
    {   
        cin>>s;
        if (um.find(s) != um.end()) 
        {
            um[s] += 1;
            ++cnt;
        }
    }

    vector<string> v;
    v.reserve(N > M ? N : M);
    for (auto it=um.begin(); it!=um.end(); ++it)
        if (it->second != 0) v.push_back(it->first);

    cout<<cnt<<'\n';
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); ++i) cout<<v[i]<<'\n';
}   