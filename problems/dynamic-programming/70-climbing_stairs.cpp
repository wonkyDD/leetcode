// https://leetcode.com/problems/climbing-stairs/
// https://leetcode.com/problems/climbing-stairs/solutions/25296/3-4-short-lines-in-every-language/comments/347475
#include <bits/stdc++.h>
using namespace std;

class Answer
{
public:
    int climbStairs(int n)
    {
        int a = 1, b = 1;
        while (--n)
        {
            int temp = b;
            b += a;
            // a = b - a;
            a = temp;
        }
        return b;
    }
};

class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[46] = {0};
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<=n; ++i)
        {
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};

/**
 * @note Time Limit Exceeded
*/
class Fail
{
public:
    int cnt = 0;
    int climbStairs(int n)
    {
        fn(n);
        return cnt;
    }

    void fn(int n)
    {
        if (n < 0) return;
        if (n == 0) ++cnt;
        fn(n-1);
        fn(n-2);
    }
};
