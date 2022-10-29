// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
using namespace std;

// N(1 ≤ N ≤ 1,000)
vector<int> node[1001];
bool found_dfs[1001];
bool found_bfs[1001];

vector<int> result_dfs; 
vector<int> result_bfs; 


void dfs(int n) {
    found_dfs[n] = true;
    result_dfs.push_back(n);

    for (int i=0; i<node[n].size(); ++i) {
        if (!found_dfs[node[n][i]]) {
            dfs(node[n][i]);
        }
    }
}

void bfs(vector<int>& v, vector<int>& temp) {
    cout<<"YES";
    for (auto it=v.begin(); it!=v.end(); ++it) {
        for (int i=0; i<node[*it].size(); ++i) {
            if (!found_bfs[node[*it][i]]) {
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

int main() {
    int N,M,V;
    cin>>N>>M>>V;

    int a,b;
    for (int i=0; i<M; ++i) {
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    // dfs(V);
    vector<int> v, temp;
    v.push_back(V);

    bfs(v, temp);
}
