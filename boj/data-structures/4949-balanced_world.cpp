// https://www.acmicpc.net/problem/4949
#include <iostream>
#include <string>
#include <stack>
using namespace std;

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
}