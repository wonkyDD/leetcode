// https://www.acmicpc.net/problem/2468
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

/**
 * @note
 * 아무 지역도 물에 잠기지 않을 수도 있다.
*/

int N;
// int mat[100][100];
bool b_mat[100][100];
bool check[100][100];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void dfs(int i, int j)
{
    check[i][j] = true;
    for (int k=0; k<4; ++k)
    {
        int ni = i+di[k], nj = j+dj[k];
        if (0<=ni && ni<N && 0<=nj && nj<N && !check[ni][nj] && b_mat[ni][nj])
            dfs(ni, nj);
    }
}

int main()
{
    cin>>N;
    int mat[N][N];
    set<int> s;

    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            cin>>mat[i][j];
            s.insert(mat[i][j]);
        }
    }
    
    /**
     * @note
     * 아무 지역도 물에 잠기지 않을 수도 있다.
    */
    // int rain, max=0;
    int rain, max=1;
    
    for (auto it=s.begin(); it!=s.end(); ++it)
    {
        rain = *it;
        
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j) 
                if (mat[i][j] > rain) b_mat[i][j] = true;
        }
            
        int cnt = 0;
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
            {
                if (b_mat[i][j] && !check[i][j]) 
                {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }

        // memset(mat, 0, sizeof(mat));
        // max = cnt > max ? cnt : max;
        cout<<'\n'<<"강수량 "<<*it<<" -> "<<cnt;
        memset(check, false, sizeof(check));
        memset(b_mat, false, sizeof(b_mat));
    }
    // cout << max;
}