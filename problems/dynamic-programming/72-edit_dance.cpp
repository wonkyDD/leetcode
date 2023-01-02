// https://leetcode.com/problems/edit-distance/
// https://leetcode.com/problems/edit-distance/solutions/25846/c-o-n-space-dp/
#include <bits/stdc++.h>
using namespace std;

class Answer
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i=1; i<=m; ++i) dp[i][0] = i;
        for (int j=1; j<=n; ++j) dp[0][j] = j;


        for (int i=1; i<=m; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else
                {
                    int res = dp[i-1][j-1] + 1;
                    res = min(res, dp[i-1][j] + 1);
                    res = min(res, dp[i][j-1] + 1);
                    dp[i][j] = res;
                }
            }
        }
        return dp[m][n];
    }
};
