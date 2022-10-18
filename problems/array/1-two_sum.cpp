// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> v;
        int i = 0;
        bool isFound = false;
        
        const size_t length = nums.size();
        
        for (; i<length-1; ++i)
        {
            for(int j=i+1; j<length; ++j)
            {
                if (nums.at(i) + nums.at(j) == target)
                {
                    isFound = true;
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
            
            if (isFound)
                break;
        }
        return v;
    }
};