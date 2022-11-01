// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N,M,temp;
    unordered_map<int, int> n_um, m_um;

    cin>>N;
    for (int i=0; i<N; ++i) {
        cin>>temp;
        n_um.insert(make_pair(temp, i));
    }

    cin>>M;
    for (int i=0; i<M; ++i) {
        cin>>temp;
        m_um.insert(make_pair(i, temp));
    }

    for (int i=0; i<M; ++i) {
        // m_um[i]
        if (n_um.find(m_um[i]) == n_um.end()) cout<<0<<'\n';
        else cout<<1<<'\n';
    }
}


/**
 * @todo
 * 실패 (2)
 * 
*/
// int main() {
//     int N,M;
//     vector<int> nv, mv;
//     cin>>N;
//     nv.reserve(N);

//     int temp;
//     for (int i=0; i<N; ++i) {
//         cin>>temp;
//         nv.push_back(temp);
//     }

//     // 기준이 M으로부터 N에 있는지 검사하는 거임
//     cin>>M;
//     mv.reserve(M);
//     for (int i=0; i<M; ++i) {
//         cin>>temp;
//         mv.push_back(temp);
//     }

//     for (int i=0; i<M; ++i) {
//         int j;
//         for (j=0; j<N; ++j) {
//             if (mv[i] == nv[j]) {
//                 cout<<1<<'\n';
//                 break;
//             }
//         }
//         if (j==N) cout<<0<<'\n';
//     }
// }


/**
 * @todo
 * 실패 (1)
 * 
*/
// int narr[100001];
// int marr[100001];

// int main() {
//     cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
//     int N,M;
//     cin>>N; for (int i=1; i<=N; ++i) cin>>narr[i];
//     cin>>M; for (int i=1; i<=M; ++i) cin>>marr[i];

//     for (int j=1; j<=N; ++j) {
//         int i;
//         for (i=1; i<=M; ++i) {
//             if (narr[i] == marr[j]) {
//                 cout<<1<<'\n'; 
//                 break;
//             }
//         }
//         if (i==M+1) cout<<0<<'\n';
//     }
// }