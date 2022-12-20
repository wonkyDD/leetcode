// https://leetcode.com/problems/generate-parentheses/
// https://leetcode.com/problems/generate-parentheses/solutions/127698/generate-parentheses/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Answer 
{
public:
    int n;
    vector<string> res;
    
    vector<string> generateParenthesis(int n) 
    {
        this->n = n;
        backtrack("");
        return res;
    }

    void backtrack(string s, int left = 0, int right = 0)
    {
        if (s.size() == 2*n)
        {
            res.push_back(s);
            return;
        }

        string temp = s;

        if (left < n)
        {
            s += '(';
            backtrack(s, left+1, right);
            s = temp;
        }

        if (right < left)
        {
            s += ')';
            backtrack(s, left, right+1);
            s = temp;
        }
    }
};

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