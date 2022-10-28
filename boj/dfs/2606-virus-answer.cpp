// https://www.acmicpc.net/problem/2606
// https://guiyum.tistory.com/40
#include <iostream>
#include <vector>
using namespace std;

// 컴퓨터 개수가 100개 이하임
vector<int> node[101];
bool found[101] = {false};
int cnt=0;

void dfs(int n) {
    found[n] = true;
    for (int i=0; i<node[n].size(); ++i) {
        if (!found[node[n][i]]) {
            dfs(node[n][i]);
            cnt++;
        }
    }
}

// num은 왜 받는 거임?
int main() {
    int num,pair;
    cin>>num>>pair;
    
    int a,b;
    for (int i=0; i<pair; ++i) {
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    
    dfs(1);
    cout<<cnt;
}