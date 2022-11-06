// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int N,K;

    cin>>N>>K;
   
    int num[N+1];
    for (int i=1; i<=N; ++i) num[i] = i;

    vector<int> answer;
    answer.reserve(N);

    int idx=K, cnt=N;
    while (true)
    {
        if (cnt == 0) break;

        int temp = cnt;
        if (idx > temp)
        {
            idx -= temp;
            for (int i=1; i<=temp; ++i) 
                if (num[i] == 0) --cnt;

            int newNum[cnt+1];
            int j=1;
            for (int i=1; i<=N; ++i)
            {
                if (j <= cnt && num[i] != 0) 
                {
                    newNum[j] = num[i];
                    ++j;
                }
            }

            memset(num, 0, sizeof(num));
            for (int i=1; i<=cnt; ++i) num[i] = newNum[i];
        }
        else 
        {
            answer.push_back(num[idx]);
            num[idx] = 0;
            idx += K;
        }
    }

    cout<<'<';
    for (int i=0; i<answer.size(); ++i)
    {
        if (i == answer.size()-1) cout<<answer[i];
        else cout<<answer[i]<<", ";
    }
    cout<<'>';
}