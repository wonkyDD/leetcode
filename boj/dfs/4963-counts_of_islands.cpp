// https://www.acmicpc.net/problem/4963
#include <iostream>
#include <cstring>
using namespace std;

int w,h;
int mat[50][50];
bool check[50][50];

// 좌, 우, 상, 하, 대각좌상, 대각우상, 대각좌하, 대각우하,  
int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};

void dfs(int _h, int _w) {
    check[_h][_w] = true;
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            int nx = _w+dx[i], ny = _h+dy[j];
            if (0<=nx && nx<w && 0<=ny && ny<h && mat[ny][nx]==1 && !check[ny][nx]) 
                dfs(ny, nx);
        }
    }
}

int main() {
    int cnt;
    while (true) {
        cnt = 0;
        cin>>w>>h;
        if (w==0 && h==0) break;
        
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                cin>>mat[i][j];
            }
        }

        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                if (mat[i][j] == 1 && !check[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        memset(mat, 0, sizeof(mat));
        memset(check, false, sizeof(check));
        cout<<cnt<<'\n';
    }   
}