// https://leetcode.com/problems/longest-valid-parentheses/
// https://leetcode.com/problems/longest-valid-parentheses/solutions/14147/my-simple-8ms-c-code/
/** @todo cant understand official solution */
// https://leetcode.com/problems/longest-valid-parentheses/solutions/127609/longest-valid-parentheses/
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Answer 
{
public:
    int longestValidParentheses(string s) 
    {
        stack<int> stk;
        stk.push(-1);
        int maxL = 0;

        for(int i=0; i<s.size(); ++i)
        {
            int t = stk.top();
            if(t != -1 && s[i]==')' && s[t]=='(')
            {
                stk.pop();
                maxL = max(maxL, i-stk.top());
            }
            else stk.push(i);
        }

        return maxL;
    }
};


/**
 * @note
 * Time Limit Exceeded (???)
*/
class AnswerFail
{
public:
    int longestValidParentheses(string s) 
    {
        int maxlen = 0;

        for (int i=0; i<s.size(); ++i)
        {
            // j means for (length + i)
            for (int j = i+2; j<=s.size(); j+=2)
            {
                if (isValid(s.substr(i, j-i)))
                {
                    maxlen = j-i > maxlen ? j-i : maxlen;
                }
            }
        }

        return maxlen;
    }

    bool isValid(string s)
    {
        stack<char> stk;
        for (int i=0; i<s.size(); ++i)
        {
            if (s[i] == '(') stk.push('(');
            else if (!stk.empty() && s[i] == ')') stk.pop();
            else return false;
        }

        return stk.empty();
    }
};

/**
 * @note
 * Time Limit Exceeded
*/
class Fail1 
{
public:
    int max = 0;

    int longestValidParentheses(string s) 
    {
        // @todo replace `while` with `for-loop`
        // @todo get indices for each of open&closed brackets in array-like
        
        vector<int> vl;
        vector<int> vr;

        for (int i=0; i<s.size(); ++i)
        {
            if (s[i] == '(') vl.push_back(i);
            else if (s[i] == ')') vr.push_back(i);
        }

        for (int i=0; i<vl.size(); ++i)
        {
            for (int j=vr.size()-1; j>=0; --j)
            {
                if (vl[i] < vr[j])
                {
                    int length = vr[j]-vl[i]+1;
                    if (length < max) break;
                    if (length%2 != 0) continue;

                    int temp = fn(s.substr(vl[i], length));
                    max = temp > max ? temp : max;
                }
                else break;
            }
        }

        return max;
    }

    int fn(string s)
    {
        int left=0, right=0;

        for (int i=0; i<s.size(); ++i)
        {
            if (left > s.size()/2) return 0;
            if (right > left) return 0;

            if (s[i] == '(') ++left;
            else ++right;
        }
        
        return s.size();
    }
};

/**
 * @note
 * Time Limit Exceeded
*/
class Fail2
{
public:
    int longestValidParentheses(string s) 
    {
        int max = 0;
        for (int i=0; i<s.size()-1; ++i)
        {
            if (s.size()-i <= max) break;
            if (s[i] == '(')
            {
                stack<char> stk;
                for (int j=i; j<s.size(); ++j)
                {
                    if (stk.empty() && j != i)
                    {
                        // max = j-i+1 > max ? j-i+1 : max;
                        max = j-i > max ? j-i : max;
                        // if (j == s.size()-1)
                    }

                    if (s[j] == '(') stk.push(s[j]);
                    else if (s[j] == ')' && stk.empty())
                    {
                        stk.push(s[j]);
                        break;
                    }
                    else 
                    {
                        char c = stk.top();
                        if (c == '(') stk.pop();
                        else stk.push(s[j]);
                    }
                }

                if (stk.empty())
                {
                    max = s.size()-i;
                }
            }
        }

        return max;
    }
};
