// https://www.acmicpc.net/problem/1012
#include <iostream>
#include <string.h>
using namespace std;

int M,N;
int cnt=0;
int mat[50][50];
bool found[50][50];
int d[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 상,하,좌,우


void dfs(int x, int y) {
    for (int i=0; i<4; ++i) {
        int dx=d[i][0], dy=d[i][1];
        if (0<=x+dx<M && 0<=y+dy<N && mat[y+dy][x+dx]==1 && !found[y+dy][x+dx]) {
            found[y+dy][x+dx] = true;
            dfs(x+dx, y+dy);
        }
    }
}

int main() {
    int T,K,a,b;
    cin>>T;
    int res[T];

    for (int t=0; t<T; ++t) {
        cin>>M>>N>>K;
        for (int i=0; i<K; ++i) {
            cin>>a>>b;
            mat[b][a] = 1;
        }

        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j){
                if (mat[i][j]==1 && !found[i][j]) {
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


// // <방법1>
// // 테스트게이스 때문에 전역으로 할당하고
// // 재활용하는 방식이 불가능해서 main으로 이동
// // int arr[50][50];

// // <방법2>
// // https://dahyeee.tistory.com/entry/c-2%EC%B0%A8%EC%9B%90-%EB%B0%B0%EC%97%B4-%EC%B4%88%EA%B8%B0%ED%99%94memset%EC%82%AC%EC%9A%A9
// // => memset으로 재활용하자
// int arr[50][50];
// bool found[50][50];
// int M,N,K;

// // 4 X 2 배열을 만드는게 더 옳을까?
// // int dx[] = {-1, 0, 1};
// // int dy[] = {-1, 0, 1};
// int d[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 상,하,0,좌,우 순서

// void dfs() {
//     // found[y][x] = true;
//     // if (arr[y][x] == 1) {
//         // for (int i=0; i<4; ++i) {
//         //     int dx=d[i][0], dy=d[i][1];
//         //     if (0<=y+dy<N && 0<=x+dx<M && !found[y+dy][x+dx] && arr[y+dy][x+dx]==1) {

//         //     }
//         // }
//     // }
//     for (int i=0; i<N; ++i) {
//         for (int j=0; j<M; ++j) {
//             if (arr[i][j] == 1 && !found[i][j]) {

//             }
            
//         }
//     }
// }

// int main() {
//     int T,x,y;
//     cin>>T;
    
//     for (int i=0; i<T; ++i) {
//         cin>>M>>N>>K;
//         for (int j=0; j<K; ++j) {
//             cin>>x>>y;
//             arr[y][x] = 1;
//         }

//         // 0, 0으로 시작해도 되겠지?
//         dfs();

//         // 다음 테스트케이스 가기전에 초기화
//         for(int k=0; k<50; ++k) memset(arr[k], 0, sizeof(int)*50);
//     }
// }
