// https://www.acmicpc.net/problem/2775
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v;

int func(int k, int n) {
    if (v[k][n] != 0) return v[k][n];
    int sum=0;
    for (int i=1; i<=n; ++i) sum += func(k-1, i);
    return v[k][n] = sum;
}

int main() {
    int T,k,n;
    cin>>T;

    while (T--) {
        v.clear();

        vector<int> f;
        f.reserve(15);
        v.push_back(f);
        for (int i=0; i<15; ++i) v[0].push_back(i);

        cin>>k>>n;
        v.reserve(k+1);

        for (int i=0; i<k; ++i) {
            vector<int> f;
            f.reserve(15);

            // f[j]=0 도 안되고
            // 그렇다고 reserve이후에 아무것도 안해도 안됨
            // func에서 v[k][n] 접근시 에러 발생
            for (int j=0; j<15; ++j) f.push_back(0);
            v.push_back(f);
        }
        cout<<func(k, n)<<'\n';
    }
}
