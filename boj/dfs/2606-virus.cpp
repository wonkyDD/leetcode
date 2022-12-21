// https://www.acmicpc.net/problem/2606
// https://guiyum.tistory.com/40
#include <iostream>
#include <vector>
using namespace std;

namespace Answer
{
// 컴퓨터 개수가 100개 이하임
vector<int> node[101];
bool found[101] = {false};
int cnt=0;

void dfs(int n) 
{
    found[n] = true;
    for (int i=0; i<node[n].size(); ++i) 
    {
        if (!found[node[n][i]]) 
        {
            dfs(node[n][i]);
            cnt++;
        }
    }
}

// num은 왜 받는 거임?
int main() 
{
    int num,pair;
    cin>>num>>pair;
    
    int a,b;
    for (int i=0; i<pair; ++i) 
    {
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    
    dfs(1);
    cout<<cnt;
}
} // namespace Answer

namespace Fail
{
struct Node 
{
    int val;
    bool found;
    vector<Node*> linked;
    Node(int x) : val(x), found(false) {}
};  
int cnt = 0;
void dfs (Node* first);

int main() {
    int n, pair;
    vector<Node> nodes;
    cin>>n;
    cin>>pair;
    
    // node 생성
    for (int i=0; i<n; ++i) 
    {
        Node n = Node(i+1);
        nodes.push_back(n);
    }

    // 연결된 주소들 node별 삽입
    int a,b;
    for (int i=0; i<pair; ++i) 
    {
        cin>>a>>b;
        nodes[a-1].linked.push_back(&nodes[b-1]);
        nodes[b-1].linked.push_back(&nodes[a-1]);
    }

    nodes[0].found = true;
    dfs(&nodes[0]);
    cout<<cnt;
}

void dfs (Node* first) 
{
    auto linked = first->linked;
    for (auto it=linked.begin(); it!=linked.end(); ++it) 
    {
        bool found = (*it)->found;
        if (!found) 
        {
            (*it)->found = true;
            cnt++;
            dfs(*it);
        }
        else break;
    }
}
} // namespace Fail
