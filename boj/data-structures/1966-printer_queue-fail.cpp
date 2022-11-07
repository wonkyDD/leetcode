// https://www.acmicpc.net/problem/1966
#include <iostream>
#include <vector>
#include <queue>
// #include <algorithm>
using namespace std;

/**
 * @todo
 * imp를 unordered_map으로 변경시
 * 주석처리
*/
void sort_desc(vector<int>& v)
{
    for (int i=0; i<v.size()-1; ++i)
    {
        for(int j=i+1; j<v.size(); ++j)
        {
            int temp;
            if (v[i] < v[j]) 
            {
                temp = v[i];
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
        vector<int> imp;
        imp.reserve(9);
        queue<pair<int, int> > q;
        
        /**
         * @todo
         * imp를 unordered_map으로 변경시
         * 상당부분 수정
        */
        for (int i=0; i<N; ++i)
        {
            cin>>num;
            q.push(make_pair(i, num));

            int j=0;
            for (; j<imp.size(); ++j)
                if (imp[j] == num) break; 
            if (j == imp.size()) imp.push_back(num);
        }
        sort_desc(imp);

        int idx=0, cnt=0; 
        while (true)
        {   
            /**
             * @todo
             * 9를 pop하고나서 
             * 이제더이상 9가 존재하지 않는다는 사실을 realtime으로 인지시켜야함.
             * 
             * 즉, 한사이클 (q.size)만큼 돌리는 방식은 옳지않고
             * imp[idx]가 몇개 존재하는지 알아야함
             * 
             * imp를 unordered_map으로 해야할 수도?
             * 
             * imp를 um으로 바꾸면 sort_desc는 필요없다.
             * (um자체가 지원하기 때문)
             * 
             * ++idx하는 타이밍도 잘 생각해야함
            */
            int size = q.size();
            for (int i=0; i<size; ++i)
            {
                auto top = q.front();
                q.pop();
                if (top.second == imp[idx])
                {
                    ++cnt;
                    if (top.first == M)
                        goto answer;
                }
                else q.push(top);
            }
            ++idx;
        }
        answer:
            cout<<cnt<<'\n';
    }
}