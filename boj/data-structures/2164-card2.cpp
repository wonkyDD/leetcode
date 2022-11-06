// https://www.acmicpc.net/problem/2164
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    queue<int> q;

    cin>>N;
    for (int i=1; i<=N; ++i) q.push(i);

    while (true) 
    {
        if (q.size() == 1) break;
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front();
}