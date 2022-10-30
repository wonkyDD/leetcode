// https://guiyum.tistory.com/41

/**
 * <놓친 점>
 * 1. memset에 for문없이 memset(arr, 0, sizeof(arr))
 * 이런 식으로 구사함
 * 
 * 
 * 2. res[t]라는 것도 사용하지 않음
 * -> 굳이 한방에 모아서 출력해야 한다는 얘기가
 * 문제에 없기는 하니까 ㅇㅇ;
 * 
 * 
 * 3. found[]=true를 dfs함수안에서 하는 위치
 * -> 난 for문 안에서 했는데, 답은 함수진입하자마자 함
 * 
 * 
 * <단순 비교>
 * - string.h가 아니라 cstring을 사용
 * - dxdy: 2차원 배열이 아닌, 길이 4짜리 배열 2개를 만들었음
*/

#include <iostream>
#include <cstring>
using namespace std;

int M,N;
int mat[50][50];
bool check[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    check[y][x] = true;
    for (int i=0; i<4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0<=nx && nx<M && 0<=ny && ny<N && mat[ny][nx]==1 && !check[ny][nx])
            dfs(nx, ny);
    }
}

// void dfs(int x, int y) {
//     check[x][y] = true;
//     for (int i=0; i<4; ++i) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if (0<=nx && nx<N && 0<=ny && ny<M && mat[nx][ny]==1 && !check[nx][ny])
//             dfs(nx, ny);
//     }
// }

int main() {
    int T,K,cnt,a,b;
    cin>>T;

    while (T--) {
        cnt=0;
        cin>>M>>N>>K;
        for (int i=0; i<K; ++i) {
            cin>>a>>b;
            mat[b][a] = 1;
        }

        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (mat[i][j]==1 && !check[i][j]) {
                    cnt++;
                    dfs(j, i);
                    // dfs(i, j);
                }
            }
        }
        // memset, cout
        memset(mat, 0, sizeof(mat));
        memset(check, false, sizeof(check));
        cout<<cnt<<'\n';
    }
}