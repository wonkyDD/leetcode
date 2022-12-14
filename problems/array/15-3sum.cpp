// https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments/8581
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Answer 
{
public:
    vector<vector<int> > threeSum(vector<int>& nums) 
    {
        // 1. 그대로 쓰지않고 미리 정렬
        sort(nums.begin(),nums.end());

        int n=nums.size();
        vector<vector<int> > res;

        for(int i=0;i<n-2;i++)
        {
            // 2. 더 넓은 집합에서 2개를 뽑는과정(nums[i-1]기준)이 선행됐으므로, 
            // nums[i]가 똑같다면 진행할 필요없음 
            if(i>0 && (nums[i]==nums[i-1]) )continue;
            
            int l=i+1, r= n-1;
            while(l<r)
            {
                int sum =nums[i]+nums[l]+nums[r];
                
                if(sum<0) l++;
                else if(sum>0)r--;
                else 
                {
                    // res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    res.push_back(v);

                    while(l+1<r && nums[l]==nums[l+1])l++;
                    while(l<r-1 && nums[r]==nums[r-1]) r--;

                    // 4. sum==0 이므로, l과 r을 동시에 변화시켜줘야 함 
                    l++; r--;
                }
            }
        }
       
        return res;
    }
};

class Fail 
{
public:
    vector< vector<int> > threeSum(vector<int>& nums) 
    {
        const int length = nums.size();
        
        vector< vector<int> > result;
        
        for (int i = 0; i < length-2; ++i) {
            for (int j = i+1; j < length - 1; ++j) 
            {
                for (int k = j+1; k < length; ++k) 
                {
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