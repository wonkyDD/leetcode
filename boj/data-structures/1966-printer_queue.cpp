// https://www.acmicpc.net/problem/1966
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sort_desc(vector<pair<int,int> >& v)
{
    for (int i=0; i<v.size()-1; ++i)
    {
        for(int j=i+1; j<v.size(); ++j)
        {
            if (v[i].first < v[j].first)
            {
                auto temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main()
{
    int T,N,M,num;
    cin>>T;

    while (T--)
    {
        cin>>N>>M;
        vector<pair<int,int> > imp;
        imp.reserve(9);
        queue<pair<int, int> > q;
        
        for (int i=0; i<N; ++i)
        {
            cin>>num;
            q.push(make_pair(i, num));

            int j=0;
            for (; j<imp.size(); ++j)
            {
                if (imp[j].first == num)
                {
                    imp[j].second += 1;
                    break;
                }
            }
            if (j == imp.size()) imp.push_back(make_pair(num, 1));
        }
        sort_desc(imp);

        int idx=0, cnt=0; 
        while (true)
        {
            auto top = q.front();
            q.pop();
            if (top.second == imp[idx].first)
            {
                ++cnt;    
                imp[idx].second -= 1;
                if (top.first == M)
                    goto answer;
            }
            else q.push(top);

            if (imp[idx].second == 0) ++idx;
        }
        answer:
            cout<<cnt<<'\n';
    }
}