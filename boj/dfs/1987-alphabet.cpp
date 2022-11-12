// https://www.acmicpc.net/problem/1987
#include <iostream>
#include <set>
#include <stack>
using namespace std;

int R,C;
char mat[21][21];
bool check[21][21];
set<char> s;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void dfs(int i, int j)
{
    check[i][j] = true;
    for (int k=0; k<4; ++k)
    {
        int ni = i+di[k], nj = j+dj[k];
        if (1<=ni && ni<=R && 1<=nj && nj<=C && !check[ni][nj])
        {
            if (s.find(mat[ni][nj]) == s.end())
            {

            }
            else
            {
                
            }
            // set에서 erase한 다음
            // stack에 보관하면서
            // dfs한번 종료될때마다 pop해서 set에 다시 insert

            /**
             * @todo
             * 일단 check를 true 상태 
             * dfs탐색 중 (끝이 아니라) 그대로 두면 안된다는 게 제일 큰 문제임. 
             * 
             * 
             * 
            */
        }
    }
}

int main()
{
    cin>>R>>C;
    for (int i=1; i<=R; ++i)
        for (int j=1; j<=C; ++j)
            cin>>mat[i][j];
    
    for (int i=65; i<91; ++i) s.insert(i);
  


    // for (auto it=s.begin(); it!=s.end(); ++it) cout<<*it<<'\n';
}