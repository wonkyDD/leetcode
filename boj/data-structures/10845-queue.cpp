// https://www.acmicpc.net/problem/10845
#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    int m_size;
    int* elem;
public:
    Queue(int max_size) : m_size(0)
    {
        elem = (int*)malloc(sizeof(int) * max_size);
    }
    void push(int n) 
    {
        m_size += 1;
        *(elem + m_size - 1) = n; // pop할때 *(elem)을 빼낼거임
    }
    int pop()
    {
        if (m_size == 0) return -1;
        m_size -= 1;
        int temp = *elem;
        for (int i=0; i<m_size; ++i) *(elem+i) = *(elem+i+1);
        return temp;

        // TODO: pop이후에 queue 멤버들을 앞으로 땅기는 작업이 있어야 함
        // for
        // *elem+i-1 = *elem+i ? ? 
    }
    int size() { return m_size; }
    bool empty() { return m_size == 0; }
    int front() { return m_size == 0 ? -1 : *elem; }
    int back() { return m_size == 0 ? -1 : *(elem + m_size - 1); }
    ~Queue() { delete[] elem; }
};

int main() 
{
    int N;
    string s;

    cin>>N;
    getchar();

    Queue q = Queue(N);
    while (N--) 
    {
        /**
         * @todo
         * 여기다 하면 안되고 위에다 해야함
        */
        // getchar();
        getline(cin, s);

        int pos_delim = s.find(" ");
        if (pos_delim == s.npos) 
        {
            if (s == "pop") cout << q.pop() << '\n';
            else if (s == "size") cout << q.size() << '\n';
            else if (s == "empty") cout << q.empty() << '\n';
            else if (s == "front") cout << q.front() << '\n';
            else cout << q.back() << '\n';
        }
        else // push
            q.push(stoi(s.substr(pos_delim + 1, s.size())));
    }
}
