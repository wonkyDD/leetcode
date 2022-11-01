// https://www.acmicpc.net/problem/10828
// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
// https://stackoverflow.com/questions/15475744/string-find-is-not-finding-spaces
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Stack {
private:
    int m_size;
    int* elem;
public:
    Stack(int n): m_size(0) {
        elem = (int*)malloc(sizeof(int) * n);
    }
    void push(int n) {
        m_size += 1;
        *(elem+m_size-1) = n;
    }
    void pop() {
        if (m_size == 0) return;
        m_size -= 1;
    }
    int size() { return m_size; }
    bool empty() { return m_size==0; }
    int top() {
        if (m_size == 0) return -1;
        return *(elem+m_size-1); 
    }
    ~Stack() { delete[] elem; }
};

int main() {
    
    /**
     * Q. 이것때매 안풀렸음;;
     * 
    */
    // cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

    int N;
    // string delim = " ";
    cin>>N; 
    Stack stk = Stack(N);
    getchar();

    while (N--) {
        string s;
        // 여기다가 두면 안됨
        // getchar();
        getline(cin, s);
        // top, size, empty, pop
        if (s.find(" ") == s.npos) {
            if (s == "top") cout<<stk.top()<<'\n';
            else if (s == "size") cout<<stk.size()<<'\n';
            else if (s == "empty") cout<<stk.empty()<<'\n';
            else { // pop
                cout<<stk.top()<<'\n';
                stk.pop();
            }
        }
        else { // push
            int num = stoi(s.substr(s.find(" ")+1, s.size()));
            stk.push(num);
        }
    }
}
