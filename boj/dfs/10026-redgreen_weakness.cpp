// https://www.acmicpc.net/problem/10026
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N;
char rgb;
char mat[100][100];
bool check[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    check[y][x] = true;
    for (int i=0; i<4; ++i) {
        int nx=x+dx[i], ny=y+dy[i];
        if (0<=nx && nx<N && 0<=ny && ny<N && mat[ny][nx]==rgb && !check[ny][nx])
            dfs(nx, ny);
    }
}

void dfs_weakness(int x, int y) {
    check[y][x] = true;
    for (int i=0; i<4; ++i) {
        int nx=x+dx[i], ny=y+dy[i];
        if (0<=nx && nx<N && 0<=ny && ny<N && !check[ny][nx]) {
            if (rgb=='B' && mat[ny][nx]==rgb) dfs_weakness(nx, ny);
            if (rgb!='B' && mat[ny][nx]!='B') dfs_weakness(nx, ny);
        }
    }
}

int main() {
    int cnt=0;
    string s;
    cin>>N;
    for (int i=0; i<N; ++i) {
        cin>>s;
        for (int j=0; j<N; ++j)
            mat[i][j] = s[j];
    }

    // 적록색약 x
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (!check[i][j]) {
                cnt++;
                rgb = mat[i][j];
                dfs(j, i);
            }
        }
    }
    cout<<cnt<<' ';

    cnt=0;
    memset(check, false, sizeof(check));

    // 적록색약 o
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (!check[i][j]) {
                cnt++;
                rgb = mat[i][j];
                dfs_weakness(j, i);
            }
        }
    }
    cout<<cnt;
}
