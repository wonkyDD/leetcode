// https://www.acmicpc.net/problem/4949
#include <iostream>
#include <string>
#include <stack>
using namespace std;

namespace Solution
{
int main()
{
    string s;
    while (true)
    {
        getline(cin, s);
        if (s == ".") break;
        stack<char> stk;

        
        for (int i=0; i<s.size(); ++i)
        {
            if (stk.empty()) 
            {
                if (s[i]==')' || s[i]==']')
                {
                    stk.push(s[i]);
                    break;
                }
                else if (s[i]=='(' || s[i]=='[') stk.push(s[i]);
            }
            else
            {
                if (s[i]=='(' || s[i]==')')
                {
                    if (stk.top() == '(' && s[i] == ')') stk.pop();
                    else if (stk.top() == '(' && s[i] == '(') stk.push(s[i]);
                    else if (stk.top() == '[' && s[i] == '(') stk.push(s[i]);
                    else break;
                }
                else if (s[i]=='[' || s[i]==']')
                {
                    if (stk.top() == '[' && s[i] == ']') stk.pop();
                    else if (stk.top() == '[' && s[i] == '[') stk.push(s[i]);
                    else if (stk.top() == '(' && s[i] == '[') stk.push(s[i]);
                    else break;
                }
            }
        }
        if (stk.empty()) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }

    return 0;
}
} // namespace Solution

namespace Fail
{
/**
 * @todo
 * Help( I[m being held prisoner in a fortune cookie factory)].
 * -> 스택을 독립적으로 2개를 만들면 위 케이스를 잡지못함
*/
int main()
{
    string s;
    while (true)
    {
        getline(cin, s);
        if (s == ".") break;

        stack<char> p,b;
        for (int i=0; i<s.size(); ++i)
        {
            if (s[i]=='(') p.push(s[i]);
            else if (s[i]==')')
            {
                if (!p.empty() && p.top()=='(') p.pop();
                else p.push(s[i]);
            }
            else if (s[i]=='[') b.push(s[i]);
            else if (s[i]==']')
            {
                if (!b.empty() && b.top()=='[') b.pop();
                else b.push(s[i]);
            }
        }

        if (p.empty() && b.empty()) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }

    return 0;
}
} // namespace Fail
