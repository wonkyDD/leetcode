// https://leetcode.com/problems/3sum/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        const int length = nums.size();
        
        vector< vector<int> > result;
        
        for (int i = 0; i < length-2; ++i) {
            for (int j = i+1; j < length - 1; ++j) {
                for (int k = j+1; k < length; ++k) {
                    // int vi = nums.at(i);
                    // int vj = nums.at(j);
                    // int vk = nums.at(k);
                    
                    int vi = nums[i];
                    int vj = nums[j];
                    int vk = nums[k];
                    
                    if (vi + vj + vk == 0) {
                        // vector<int> v = {vi, vj, vk};
                        vector<int> v;
                        v.push_back(vi);
                        v.push_back(vj);
                        v.push_back(vk);
                        
                        result.push_back(v);
                    }
                }
            }
          }
        
        // for(vector<int> v: res)
        
        return result;
    }
};
