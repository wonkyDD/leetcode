// https://leetcode.com/problems/interleaving-string/
// https://leetcode.com/problems/interleaving-string/solutions/31879/my-dp-solution-in-c/
// https://leetcode.com/problems/interleaving-string/solutions/31879/my-dp-solution-in-c/comments/30699
#include <bits/stdc++.h>
using namespace std;

class Answer2
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size(), l = s3.size();
        if (l != m+n) return false;
        if (m > n) return isInterleave(s2, s1, s3);

        bool *dp = new bool[m+1]();
        dp[0] = true;
        
        for (int i=1; i<=m; ++i)
            dp[i] = dp[i-1] && s1[i-1] == s3[i-1];

        for (int j=1; j<=n; ++j)
        {
            dp[0] = dp[0] && s2[j-1] == s3[j-1];
            for (int i=1; i<=m; ++i)
            {
                dp[i] = (dp[i-1] && s3[i+j-1] == s1[i-1]) || (dp[i] && s3[i+j-1] == s2[j-1]);
            }
        }
        return dp[m]; 
    }
};

class Answer1
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();
        if (s3.size() != m+n) return false;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // dp[0][0] = true;
        // for (int i=1; i<=m; ++i) dp[i][0] = s1.substr(0, i) == s3.substr(0, i);
        // for (int i=1; i<=n; ++i) dp[0][i] = s2.substr(0, i) == s3.substr(0, i);

        for (int i=0; i<=m; ++i)
        {
            for (int j=0; j<=n; ++j)
            {
                if (i==0 && j==0) dp[i][j] = true;
                else if (i==0)
                {
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                else if (j==0)
                {
                    dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i-1+j];
                }
                else
                {
                    // dp[i][j] = dp[i-1][j-1] && 
                    // ((s1[i-1]==s3[i+j-2] && s2[j-1]==s3[i+j-1]) || 
                    // (s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-2]));
                    
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i-1+j]);
                }
            }
        }
        return dp[m][n];
    }
};

/**
 * @note Time Limit Exceeded
*/
class Fail
{
public:
    bool isInterleave(string s1, string s2, string s3, int n=0, int m=0)
    {
        if (abs(n-m) > 1) return false;
        if (abs(n-m) <= 1 && !s1.size() && !s2.size()&& !s3.size()) return true;

        for (int i=1; i<=s3.size(); ++i)
        {
            bool res;
            if (s3.substr(0, i) == s1.substr(0, i))
                res = isInterleave(s1.substr(i, s1.size()-i), s2, s3.substr(i, s3.size()-i), n+1, m);
            if (res) return true;

            if (s3.substr(0, i) == s2.substr(0, i))
                res = isInterleave(s1, s2.substr(i, s2.size()-i), s3.substr(i, s3.size()-i), n, m+1);
            if (res) return true;
        }

        return false;
    }
};
