// https://leetcode.com/problems/unique-binary-search-trees/
// https://leetcode.com/problems/unique-binary-search-trees/solutions/1565543/c-python-5-easy-solutions-w-explanation-optimization-from-brute-force-to-dp-to-catalan-o-n/
#include <bits/stdc++.h>
using namespace std;

class Answer2
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;

        for (int i=2; i<=n; ++i)
            for (int j=1; j<=i; ++j)
                dp[i] += dp[j-1] * dp[i-j];

        return dp[n];
    }
};

class Answer1
{
public:
    int dp[20] = {0};
    int numTrees(int n)
    {
        if (n <= 1) return 1;
        if (dp[n]) return dp[n];

        for (int i=1; i<=n; ++i)
            dp[n] += numTrees(i-1) * numTrees(n-i);
            
        return dp[n];
    }
};

class Solution
{
public:
    int numTrees(int n)
    {
        int dp[20] = {0};
        dp[0] = 1;
        for (int i=1; i<=n; ++i)
        {
            if (i%2 == 0)
            {
                for (int j=i-1; j>=i/2; --j) dp[i] += 2*dp[j]*dp[i-1-j];
            }
            else
            {
                for (int j=i-1; j>(i-1)/2; --j) dp[i] += 2*dp[j]*dp[i-1-j];
                dp[i] += dp[(i-1)/2]*dp[(i-1)/2];
            }
        }
        return dp[n];
    }
};
