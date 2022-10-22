// https://leetcode.com/problems/3sum-closest/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        // if(len < 3) return 0;

        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        unsigned int diff = result > target ? result-target : target-result;
        
        for(int i=0; i<len-2; ++i) {
            // 
            if (i>0 && nums[i] == nums[i-1]) continue;
            
            int l = i+1;
            int r = len-1;
            
            while (l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                unsigned int newDiff;
            
                if (sum == target) 
                    return sum;
                else if (sum > target) {
                    r--;
                    newDiff = sum - target;
                }
                else {
                    l++;
                    newDiff = target - sum;
                }
                
                if (diff > newDiff) {
                    diff = newDiff;
                    result = sum;
                }
            }
        }
        return result;
    }
};



// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int len = nums.size();
        
//         unordered_map<int, unsigned int> um;
        
//         for(int i=0; i<len-2; ++i) {
//             for(int j=i+1; j<len-1; ++j) {
//                 for(int k=j+1; k<len; ++k) {
//                     int sum = nums[i]+nums[j]+nums[k];
//                     um[sum] = sum > target ? sum-target : target-sum;
//                 }
//             }
//         }
        
//         auto res = um.begin();
        
//         for (auto it=um.begin(); it!=um.end(); ++it) {
//             res = it->second > res->second ? res : it;
//         }
        
//         return res->first;
//     }
// };



// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         int len = nums.size();
//         int result = nums[0] + nums[1] + nums[2];
//         int preDiff = target > result ? target-result : result-target;

        
//         for(int i=0; i<len-2; ++i) {
//             for(int j=i+1; j<len-1; ++j) {
//                 for(int k=j+1; k<len; ++k) {
//                     int sum = nums[i]+nums[j]+nums[k];
                    
//                     if (target == sum) {
//                         return sum;
//                     }
//                     else {
//                         int diff = target > sum ? target-sum : sum-target;
//                         result = preDiff > diff ? sum : result;
                        
//                         preDiff = preDiff > diff ? diff : preDiff;
//                         // preDiff = diff;
//                     }

//                 }
//             }
//         }
//         return result;
//     }
// };
