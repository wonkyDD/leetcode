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

namespace Answer
{
int M,N;
int mat[50][50];
bool check[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) 
{
    check[y][x] = true;
    for (int i=0; i<4; ++i) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0<=nx && nx<M && 0<=ny && ny<N && mat[ny][nx]==1 && !check[ny][nx])
            dfs(nx, ny);
    }
}

int main() 
{
    int T,K,cnt,a,b;
    cin>>T;

    while (T--) 
    {
        cnt=0;
        cin>>M>>N>>K;
        for (int i=0; i<K; ++i) 
        {
            cin>>a>>b;
            mat[b][a] = 1;
        }

        for (int i=0; i<N; ++i) 
        {
            for (int j=0; j<M; ++j) 
            {
                if (mat[i][j]==1 && !check[i][j]) 
                {
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
} // namespace Answer

namespace Fail
{
int M,N;
int cnt=0;
int mat[50][50];
bool found[50][50];
int d[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 상,하,좌,우


void dfs(int x, int y) 
{
    for (int i=0; i<4; ++i) 
    {
        int dx=d[i][0], dy=d[i][1];
        if (0<=x+dx<M && 0<=y+dy<N && mat[y+dy][x+dx]==1 && !found[y+dy][x+dx]) 
        {
            found[y+dy][x+dx] = true;
            dfs(x+dx, y+dy);
        }
    }
}

int main() 
{
    int T,K,a,b;
    cin>>T;
    int res[T];

    for (int t=0; t<T; ++t) 
    {
        cin>>M>>N>>K;
        for (int i=0; i<K; ++i) 
        {
            cin>>a>>b;
            mat[b][a] = 1;
        }

        for (int i=0; i<N; ++i) 
        {
            for (int j=0; j<M; ++j)
            {
                if (mat[i][j]==1 && !found[i][j]) 
                {
                    dfs(j, i);
                    cnt++;
                }
                // mat[i][j]
            }
        }
        for (int i=0; i<50; ++i) memset(mat[i], 0, sizeof(int)*50); 
        for (int i=0; i<50; ++i) memset(found[i], false, sizeof(bool)*50); 
        
        res[t] = cnt;
        cnt = 0;
    }
    for (int i=0; i<T; ++i) cout<<res[i]<<'\n';
}
} // namespace Fail
