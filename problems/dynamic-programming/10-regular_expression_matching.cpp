// https://leetcode.com/problems/regular-expression-matching/
// https://leetcode.com/problems/regular-expression-matching/solutions/5684/c-o-n-space-dp/comments/6792
#include <vector>
using namespace std;

class Answer
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
                    dp[i][j] = i>0 && dp[i-1][j-1] && (p[j-1] == '.' || s[i-1] == p[j-1]);
                }
                else
                {
                    dp[i][j] = dp[i][j-2] || (i>0 && dp[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2]));
                }
            }
        }

        return dp[n][m];
    }
};
