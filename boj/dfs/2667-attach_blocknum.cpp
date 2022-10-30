// https://www.acmicpc.net/problem/2667
// https://nanyoungkim.tistory.com/62
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N,cnt = 0;
int mat[25][25];
bool check[25][25];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void dfs(int i, int j) {
    cnt++;
    check[i][j] = true;
    for (int k=0; k<4; ++k) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (0<=ni && ni<N && 0<=nj && nj<N && mat[ni][nj]==1 && !check[ni][nj])
            dfs(ni, nj); 
    }
}

int main() {
    // int a;
    vector<int> v;
    string s;
    cin>>N;
    for (int i=0; i<N; ++i) {
        cin>>s;
        for (int j=0; j<N; ++j) {
            // cin>>a;
            // mat[i][j] = a;
            int num = s[j]-48;
            mat[i][j] = num;
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (mat[i][j]==1 && !check[i][j])
                dfs(i, j);
            
            if (cnt != 0) {
                v.push_back(cnt);
                cnt = 0;
            }
        }
        // if (cnt != 0) {
        //     v.push_back(cnt);
        //     cnt = 0;
        // }
    }

    sort(v.begin(), v.end());
    cout <<v.size()<<'\n';
    for (auto it=v.begin(); it!=v.end(); ++it) cout<<*it<<'\n';
}
