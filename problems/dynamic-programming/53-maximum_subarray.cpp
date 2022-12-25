// https://leetcode.com/problems/maximum-subarray/
// https://leetcode.com/problems/maximum-subarray/solutions/20193/dp-solution-some-thoughts/
#include <vector>
using namespace std;

class Answer 
{
public:
    int max;

    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp;
        dp.reserve(n+1);
        dp[0] = 0;
        int max = nums[0];
        for (int i=1; i<n+1; ++i)
        {
            dp[i] = nums[i-1] + (dp[i-1] > 0 ? dp[i-1] : 0);
            max = dp[i] > max ? dp[i] : max;
        }
        return max;
    }
};

/**
 * @note Time Limit Exceeded
*/
class Fail3
{
public:
    int max;

    int maxSubArray(vector<int>& nums) 
    {
        int left=0, right=nums.size()-1;
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) sum+=nums[i];
        max = sum;
        fn(nums, left, right, sum);
        return max;
    }

    void fn(vector<int>& nums, int left, int right, int sum)
    {
        if (left > right) return;
        max = sum > max ? sum : max;
        fn(nums, left+1, right, sum-nums[left]);
        fn(nums, left, right-1, sum-nums[right]);
    }
};

/**
 * @note Time Limit Exceeded
*/
class Fail2
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max;
        for (int i=0; i<nums.size(); ++i)
        {
            int sum = nums[i];
            if (i==0) max = sum;
            for (int j=i; j<nums.size(); ++j)
            {
                if (j!=i) sum += nums[j];
                max = sum > max ? sum : max;
            }
        }
        return max;
    }
};

class Fail1
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int left, right;
        int max, sum;
        for (int i=0; i<nums.size(); ++i)
        {
            sum = nums[i];
            left = i-1;
            right = i+1;
            while (left>=0 && nums[left] >=0)
            {
                sum += nums[left];
                --left;
            }
            while (right<nums.size() && nums[right] >=0)
            {
                sum += nums[right];
                ++right;
            }
            if(i==0) max = sum;
            else max = sum > max ? sum : max;
        }
        return max;
    }
};
