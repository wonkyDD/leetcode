// https://leetcode.com/problems/jump-game/
// https://leetcode.com/problems/jump-game/solutions/20917/linear-and-simple-solution-in-c/
#include <vector>
using namespace std;

class Answer
{
public:
    bool canJump(vector<int>& nums) 
    {
        int i = 0;
        for (int reach = 0; i<nums.size() && i<=reach; ++i)
        {
            reach = i+nums[i] > reach ? i+nums[i] : reach;
        }

        return i == nums.size();
    }
};

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        dp[1] = true;
        for (int i=1; i<n+1; ++i)
        {
            for (int j=1; j<i; ++j)
            {
                if (dp[i-j] && nums[i-j-1] + i-j-1 >= i-1)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

/**
 * @note Time Limit Exceeded
*/
class Fail1
{
public:
    bool canJump(vector<int>& nums) 
    {
        return fn(nums, 0);
    }

    bool fn(vector<int>& nums, int idx)
    {
        if (idx >= nums.size()-1) return true;
        if (nums[idx] == 0 && idx < nums.size()-1) return false;
        
        // nums[idx]
        bool res = false;
        for (int i=nums[idx]; i>0; --i)
        {
            res = fn(nums, i+idx);
            if (res) break;
        }

        return res;
    }
};
