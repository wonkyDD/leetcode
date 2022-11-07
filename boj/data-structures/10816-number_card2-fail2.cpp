// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
using namespace std;

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