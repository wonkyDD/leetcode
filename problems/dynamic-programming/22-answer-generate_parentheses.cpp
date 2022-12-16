// https://leetcode.com/problems/generate-parentheses/
// https://leetcode.com/problems/generate-parentheses/solutions/127698/generate-parentheses/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution 
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