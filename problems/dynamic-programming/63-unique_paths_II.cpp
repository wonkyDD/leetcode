// https://leetcode.com/problems/unique-paths-ii/description/
// https://leetcode.com/problems/unique-paths-ii/solutions/23252/4ms-o-n-dp-solution-in-c-with-explanations/
// https://leetcode.com/problems/unique-paths-ii/solutions/23252/4ms-o-n-dp-solution-in-c-with-explanations/comments/22640
#include <bits/stdc++.h>
using namespace std;

class Answer2
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<int> dp(col, 0);
        dp[0] = 1;

        for (int i=0; i<row; ++i)
        {
            for (int j=0; j<col; ++j)
            {
                if (obstacleGrid[i][j]) dp[j] = 0; 
                else if (j>=1) dp[j] += dp[j-1];
            }
        }

        return dp[col-1];
    } 
};

class Answer1
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        // dp[1][0] = 1;
        dp[0][1] = 1;
        for (int i=1; i<=row; ++i)
            for (int j=1; j<=col; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[row][col];
    } 
};

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if (obstacleGrid[0][0]) return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        dp[0][0] = 1;
        bool b = false;
        for (int i=1; i<m; ++i)
        {
            if (b) dp[i][0] = 0;
            else if (obstacleGrid[i][0]) 
            {
                dp[i][0] = 0;
                b = true;
            }
        }

        b = false;
        for (int i=1; i<n; ++i)
        {
            if (b) dp[0][i] = 0;
            else if (obstacleGrid[0][i]) 
            {
                dp[0][i] = 0;
                b = true;
            }
        }

        for (int i=1; i<m; ++i)
        {
            for (int j=1; j<n; ++j)
            {
                if (obstacleGrid[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
