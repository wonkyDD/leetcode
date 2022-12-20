// https://leetcode.com/problems/3sum-closest/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int len = nums.size();
        // if(len < 3) return 0;

        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        unsigned int diff = result > target ? result-target : target-result;
        
        for(int i=0; i<len-2; ++i) 
        {
            // 
            if (i>0 && nums[i] == nums[i-1]) continue;
            
            int l = i+1;
            int r = len-1;
            
            while (l<r) 
            {
                int sum = nums[i] + nums[l] + nums[r];
                unsigned int newDiff;
            
                if (sum == target) return sum;
                else if (sum > target) 
                {
                    r--;
                    newDiff = sum - target;
                }
                else 
                {
                    l++;
                    newDiff = target - sum;
                }
                
                if (diff > newDiff) 
                {
                    diff = newDiff;
                    result = sum;
                }
            }
        }
        return result;
    }
};

class Answer 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        
        int len = nums.size();
        // if(len < 3) return 0;
        // Constraints: 3 <= nums.length <= 500
        
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        
        for (int i=0; i<len-2; ++i) 
        {
            if (i>0 && nums[i]==nums[i-1]) continue;
                
            int l = i+1;
            int r = len-1;
            
            while (l<r) 
            {
                int curSum = nums[i] + nums[l] + nums[r];
                if (curSum == target) return curSum;
                
                if (curSum > target) --r;
                else ++l;
                
                // abs
                if (abs(closest-target) > abs(curSum-target)) 
                {
                    closest = curSum;
                }
            }
        }
        return closest;
    };
};
