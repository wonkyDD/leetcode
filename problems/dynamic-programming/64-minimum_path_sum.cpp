// https://leetcode.com/problems/minimum-path-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        dp[m][n] = grid[m-1][n-1];
        for (int i=n-2; i>=0; --i)
            dp[m][i+1] += dp[m][i+2] + grid[m-1][i];

        for (int i=m-2; i>=0; --i)
            dp[i+1][n] = dp[i+2][n] + grid[i][n-1];

        for (int i=m-1; i>=1; --i)
            for (int j=n-1; j>=1; --j)
                dp[i][j] = grid[i-1][j-1] + min(dp[i+1][j], dp[i][j+1]);

        return dp[1][1];
    }
};

/**
 * @note Time Limit Exceeded
*/
class Fail1
{
public:
    int res;
    int m,n;
    int minPathSum(vector<vector<int>>& grid)
    {
        m = grid.size(), n = grid[0].size();
        fn(grid);
        return res;
    }

    void fn(vector<vector<int>>& grid, int i=0, int j=0, int sum=0)
    {
        if (i>m-1 || j>n-1) return;

        if (i==m-1 && j==n-1)
        {
            if (!res) res = sum + grid[i][j];
            else res = min(sum + grid[i][j], res);
            return;
        }

        fn(grid, i+1, j, sum + grid[i][j]);
        fn(grid, i, j+1, sum + grid[i][j]);
    }
};
