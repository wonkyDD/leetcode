// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v;
        int i = 0;
        bool isFound = false;
        
        // TODO: comparison of integers of different signs: 'int' and 'unsigned long' 
        // const size_t length = nums.size();
        const int length = nums.size();
        
        for (; i<length-1; ++i) {
            for(int j=i+1; j<length; ++j) {
                if (nums.at(i) + nums.at(j) == target) {
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

class Answer 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> imap;
        
        for (int i = 0;; ++i) 
        {
            auto it = imap.find(target - nums[i]);
            if (it != imap.end())  return vector<int> {i, it->second};
            imap[nums[i]] = i;
        }
    }
};
