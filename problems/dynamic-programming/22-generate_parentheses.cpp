// https://leetcode.com/problems/generate-parentheses/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution 
{
public:
    vector<string> v;

    vector<string> generateParenthesis(int n) 
    {
        /** 
         * @todo 
         * v.reserve(2n C n);
        */
        
        vector<string> res;
        string s;
        fn("", n, n);

        for (int i=0; i<v.size(); ++i)
        {
            s = v[i];
            stack<char> stk;

            for (int j=0; j<s.size(); ++j)
            {
                if (stk.empty()) stk.push(s[j]);
                else 
                {
                    char top = stk.top();
                    if (top == '(' && s[j] == '(') stk.push(s[j]);
                    else if (top == '(' && s[j] == ')') stk.pop();
                    else if (top == ')' && s[j] == '(') stk.push(s[j]);
                    else if (top == ')' && s[j] == ')') break;
                }
            }

            if (stk.empty()) res.push_back(s);
        }

        return res;
    }

    void fn(string s, int a, int b)
    {
        if (a == 0 && b == 0)
        {
            v.push_back(s);
            return;
        }

        if (a != 0) fn(s + '(', a - 1, b);
        if (b != 0) fn(s + ')', a, b - 1);
    }
};
