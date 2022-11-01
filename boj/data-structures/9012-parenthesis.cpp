// https://www.acmicpc.net/problem/9012
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

// 하나의 괄호 문자열의 길이는 2 이상 50 이하이다
// ( == 0, ) == 1 으로 취급
int arr[50];

int main() {
    int T;
    string s;
    cin>>T;

    while (T--) {
        memset(arr, 0, sizeof(arr));
        /**
         * Q. stack을 매번 새로 선언하는게 효율적일까,
         * n^2으로 가도 pop을 해서 재사용을 하는게 효율적일까?
         * while(!s.empty()) stk.pop();
        */
        stack<int> stk;
        cin>>s;

        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') arr[i] = 0;
            else arr[i] = 1;
        }

        for (int i=0; i<s.size(); ++i) {
            if (arr[i]==0) stk.push(0);
            else { // arr[i] == 1
                if (!stk.empty() && stk.top() == 0) stk.pop();
                else stk.push(1);
            }
        }

        if (stk.empty()) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}