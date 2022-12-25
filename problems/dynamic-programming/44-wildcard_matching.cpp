// https://leetcode.com/problems/wildcard-matching/
// https://leetcode.com/problems/wildcard-matching/solutions/1001130/c-clean-and-concise-bottom-up-dp-code-with-detailed-explanation-easy-to-understand/
#include <vector>
using namespace std;

class Answer
{
public:
    bool isMatch(string s, string p) 
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;
        for (int i=0; i<n && p[i] == '*'; ++i)
        {
            dp[0][i+1] = true;
        }

        for (int i=1; i<=m; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                if (p[j-1] != '*')
                {
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == '?' || s[i-1] == p[j-1]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }

        return dp[m][n];
    }
};

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        
        for (int i=0; i<n+1; ++i)
        {
            for (int j=1; j<m+1; ++j)
            {
                if (p[j-1] != '*')
                {
                    dp[i][j] = i>0 && dp[i-1][j-1] && (p[j-1] == '?' || s[i-1] == p[j-1]);
                }
                else
                {
                    if (dp[i][j-1]) dp[i][j] = true;
                    else
                    {
                        bool res = false;
                        for (int k=0; k<i; ++k)
                        {
                            if (dp[k][j-1])
                            {
                                res = true;
                                break;
                            }
                        }
                        dp[i][j] = res;
                    }
                }
            }
        }

        return dp[n][m];
    }
};
