// https://leetcode.com/problems/two-sum/discuss/13/Accepted-C%2B%2B-O(n)-Solution
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;
        
        for (int i = 0;; ++i) {
            auto it = imap.find(target - nums[i]);
            
            if (it != imap.end()) 
                return vector<int> {i, it->second};
                
            imap[nums[i]] = i;
        }
    }
};

int main() {
    return 0;
}
