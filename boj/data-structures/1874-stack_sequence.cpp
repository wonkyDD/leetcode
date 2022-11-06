// https://www.acmicpc.net/problem/1874
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n,num;
    stack<int> stk;

    cin>>n;
    int original[n];
    vector<char> answer;

    for (int i=0; i<n; ++i)
    {
        cin>>num;
        original[i] = num;
    }

    int idx=0;
    for (int curNum=1; curNum<=n; ++curNum) 
    {
        stk.push(curNum);
        answer.push_back('+');

        if (original[idx] == curNum) 
        {
            // ++idx;
            while (!stk.empty() && original[idx]==stk.top())
            {
                stk.pop();
                answer.push_back('-');
                ++idx;
            }
        }
        // else
        // {
        //     stk.push(curNum);
        //     answer.push_back('+');
        // }
    }

    // stk.empty로 answer출력여부 결정
    if (stk.empty()) 
    {
        for (auto it=answer.begin(); it!=answer.end(); ++it)
            cout<<*it<<'\n';
    }
    else cout<<"NO";
}