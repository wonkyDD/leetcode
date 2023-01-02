// https://leetcode.com/problems/jump-game-ii/
// https://leetcode.com/problems/jump-game-ii/solutions/1192401/easy-solutions-w-explanation-optimizations-from-brute-force-to-dp-to-greedy-bfs/
#include <bits/stdc++.h>
using namespace std;

class Answer2
{
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size(), i = 0, maxReach = 0, lastPos = 0, jump = 0;
        while (i < n-1)
        {
            maxReach = max(maxReach, i+nums[i]);
            if (i == lastPos)
            {
                lastPos = maxReach;
                ++jump;
            }
            ++i;
        }
        return jump;
    }
};

class Answer1
{
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n+1, 10001);
        dp[n] = 0;
        for (int i=n-1; i>=1; --i)
            for (int j=1; j<=nums[i-1]; ++j)
                dp[i] = min(dp[i], 1+dp[min(n, i+j)]);
        return dp[1];
    }
};

class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        for (int i=1; i<=nums.size(); ++i)
        {
            int min = 0;
            for (int j=1; j<i; ++j)
            {
                if (nums[i-j-1] + i-j-1 >= i-1)
                {
                    if(!min) min = dp[i-j]+1;
                    else min = dp[i-j]+1 < min ? dp[i-j]+1 : min;
                }
            }
            dp[i] = min;
        }
        return dp[nums.size()];
    }
};

/**
 * @note Time Limit Exceeded
*/
class Fail1
{
public:
    int res;

    int jump(vector<int>& nums) 
    {
        fn(nums);
        return res;
    }

    void fn(vector<int>& v, int idx = 0, int cnt = 0)
    {
        if (idx > v.size()-1) return;

        if (idx == v.size()-1)
        {
            if (!res) res = cnt;
            else res = cnt < res ? cnt : res;
        }
        
        for (int i=1; i<=v[idx]; ++i)
        {
            fn(v, idx+i, cnt+1);
        }
    }
};
