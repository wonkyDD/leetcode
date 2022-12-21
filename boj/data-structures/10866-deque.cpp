// https://www.acmicpc.net/problem/10866
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

namespace Fail
{
/**
 * @todo
 * 1. 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다
 * 2.주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다
 * -> 위 2개 조건에서 제한적으로 적용되는 구조이다.
 * 
 * // fail
 * 결국 pop_front를 계속하다보면
 * 이렇게 front와 back사이 공백을 두게되면
 * front == back이 되는 상황을 기술하지 못함.
*/
class deque
{
private:
    int m_size;
    int* elem;
    int* pFront;
    int* pBack;
public:
    deque(int n) : m_size(0)
    {
        elem = (int*)malloc(sizeof(int) * n);
        pFront = elem;
        pBack = elem + n - 1;
    }
    ~deque() { delete[] elem; }
    void push_front(int num) 
    {
        // 한칸씩 뒤로 밀기
        int tempNum = num;
        for (int* temp = pFront; tempNum != 0; ++temp)
        {
            int t = *temp;
            *temp = tempNum;
            tempNum = t;
        }
        ++m_size;
    }
    void push_back(int num)
    {
        // 한칸씩 앞으로 밀기
        int tempNum = num;
        for (int* temp = pBack; tempNum != 0; --temp)
        {
            int t = *temp;
            *temp = tempNum;
            tempNum = t;
        }
        ++m_size;
    }
    int pop_front()
    {
        // 한칸씩 앞으로 당기기
        if (m_size == 0) return -1;

        int frontVal = *pFront;
        for (int* temp = pFront; *temp != 0; ++temp)
            *temp = *(temp+1);
        --m_size;
        return frontVal;
    }
    int pop_back()
    {
        // 한칸씩 뒤로 당기기
        if (m_size == 0) return -1;

        int backVal = *pBack;
        for (int* temp = pBack; *temp != 0; --temp)
            *temp = *(temp-1);
        --m_size;
        return backVal;
    }
    /**
     * @todo
     * const 선언?
    */
    int size() { return m_size; } 
    int empty() { return m_size == 0 ? 1 : 0;} 
    int front() { return *pFront; } 
    int back() { return *pBack; } 
};

int main()
{
    string s;
    int N;

    cin>>N;
    getchar();
    deque dq(N);

    // deque dq(10);
    // dq.push_back(1);
    // dq.push_front(2);
    // dq.push_front(8);
    // cout<<dq.front()<<'\n';
    // dq.pop_front();
    // cout<<dq.front()<<'\n';
    // cout<<dq.front()<<'\n';

    while (true)
    {
        getline(cin, s);
        if (s.find(" ") == s.npos)
        {
            if (s == "pop_front") cout<<dq.pop_front()<<'\n';
            else if (s == "pop_back") cout<<dq.pop_back()<<'\n';
            else if (s == "front") cout<<dq.front()<<'\n';
            else if (s == "back") cout<<dq.back()<<'\n';
            else if (s == "size") cout<<dq.size()<<'\n';
            else if (s == "empty") cout<<dq.empty()<<'\n';
        }
        else // push_front, push_back
        {
            string cmd = s.substr(0, s.find(" ")-1);
            int num = stoi(s.substr(s.find(" ")+1, s.size()));

            if (cmd == "push_front") dq.push_front(num);
            else dq.push_back(num);
        }
    }
}
} // namespace Fail
