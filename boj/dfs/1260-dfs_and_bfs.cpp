// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

namespace Answer
{
// https://jun-itworld.tistory.com/18
/**
 * 1. cout을 굳이 모아서 하려고 했다.
 * 
 * ->  dfs, bfs 함수 안에서 해도 되는 건데, 
 * result_dfs, result_bfs로 따로 나눠서 한번에 모아
 * main에서 출력하려고 했음.
 * 
 * 
 * 2. found_bfs, found_dfs로 나눠서 방문상태를 저장하려고 했다.
 * 
 * -> 하나의 found[1001]로 
 * 먼저 dfs를 통해 0에서 1로 바뀐걸 기준으로,
 * bfs관점에선 1을 0으로 바꾸면 되는 것이다.
 * 
 * 
 * <차이점 비교>
 * - bfs에서 파라미터 구성이 dfs와 동일하다.
 * - bfs에서 재귀함수를 호출하지 않는다.
 * - bfs에서 queue를 사용한다.
 * - 배열-벡터가 아닌 인접행렬 개념을 사용한 이차원 배열.
 * - 인접행렬을 하다보니, dfs&bfs안에서 mat[v][i] == 0 이라는 조건이 추가된다.
*/
#include <iostream>
#include <queue>
using namespace std;


int found[1001];
int mat[1001][1001];


void dfs(int n) 
{
    found[n] = 1;
    cout<<n<<' ';
    for (int i=1; i<1001; ++i) 
    {
        if (found[i]==0 && mat[n][i]==1) dfs(i);
    }
}

void bfs(int n) 
{
    queue<int> q;
    q.push(n);

    while (!q.empty()) 
    {
        int first = q.front();
        cout<<first<<' ';

        // 이걸 해줘야 함
        found[first] = 0;

        for (int i=1; i<1001; ++i) {
            // 솔직히 found[i]를 dfs이후에 1,0으로 판단하는 방식이
            // 완벽하게 체화되지는 않은듯함.
            if (found[i]==1 && mat[first][i]==1) {
                found[i] = 0;
                // cout<<i<<' ';
                q.push(i);
            }
        }
        q.pop();
    }
}

int main() 
{
    int N,M,V;
    cin>>N>>M>>V;

    int a,b;
    for (int i=0; i<M; ++i) 
    {
        cin>>a>>b;
        mat[a][b] = mat[b][a] = 1;
    }

    dfs(V);
    cout<<'\n';
    bfs(V);
}
} // namespace Answer

namespace Fail
{
// N(1 ≤ N ≤ 1,000)
vector<int> node[1001];
bool found_dfs[1001];
bool found_bfs[1001];

vector<int> result_dfs; 
vector<int> result_bfs; 

void dfs(int n) 
{
    found_dfs[n] = true;
    result_dfs.push_back(n);

    for (int i=0; i<node[n].size(); ++i) 
    {
        if (!found_dfs[node[n][i]]) 
        {
            dfs(node[n][i]);
        }
    }
}

void bfs(vector<int>& v, vector<int>& temp) 
{
    cout<<"YES";
    for (auto it=v.begin(); it!=v.end(); ++it) 
    {
        for (int i=0; i<node[*it].size(); ++i) 
        {
            if (!found_bfs[node[*it][i]]) 
            {
                found_bfs[node[*it][i]] = true;
                result_bfs.push_back(node[*it][i]);

                temp.push_back(node[*it][i]);
            }
        }
    }

    v.clear();
    v.shrink_to_fit();
    bfs(temp, v);
}

int main() 
{
    int N,M,V;
    cin>>N>>M>>V;

    int a,b;
    for (int i=0; i<M; ++i) 
    {
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    // dfs(V);
    vector<int> v, temp;
    v.push_back(V);

    bfs(v, temp);
}
} // namespace Fail
