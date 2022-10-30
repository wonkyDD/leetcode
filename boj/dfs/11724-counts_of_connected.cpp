// https://www.acmicpc.net/problem/11724
#include <iostream>
using namespace std;

/**
 * 1) 특정 i에 대해, mat[i][j] 값들이 모두 0이면
 * 해당 노드는 완전고립이므로 카운팅해줘야 한다.
 * 
 * 
 * 2) main에서 if안의 dfs를 실행시키는 블록에 진입했다고해서
 * cnt++를 해주는 것이 옳을까?
 * 
 * -> 결국 main에서 처음 for문에 들어갈때
 * check[i] = true를 해주는데 이는 내부 for문을 모두 검증했다라는 의미이기에
 * 당연히 빠져나와서 cnt++를 해줘야한다.
 * 
 * 다만, dfs를 실행시켰는지 여부를 알아야 하므로
 * bool test와 같이 temp boolean을 이용해서 외부판단한다.
 * 
 * 
 * <결론>
 * dfs를 했건, 고립됐건 결국 cnt++를 해야하므로
 * 2)는 필요없이 그냥 cnt++해주면 된다.
 * 
*/
int N,M,cnt=0;
int mat[1001][1001];
bool check[1001];

void dfs(int n) {
    check[n] = true;
    for (int i=1; i<=N; ++i) {
        if (mat[n][i]==1 && !check[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin>>N>>M;
    int a,b;
    for (int i=0; i<M; ++i) {
        cin>>a>>b;
        mat[a][b] = mat[b][a] = 1;
    }

    for (int i=1; i<=N; ++i) {
        if (check[i]) continue;
        check[i] = true;

        // bool test = false;
        for (int j=1; j<=N; ++j) {
            if (mat[i][j]==1 && !check[j]) {
                dfs(j);
                // test = true;
            }
        }

        // 1), 2) 어떤 방향이건 결국 1을 더해줘야함
        cnt++;
    }
    cout<<cnt;
}