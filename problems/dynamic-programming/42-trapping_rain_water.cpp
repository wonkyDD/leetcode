// https://leetcode.com/problems/trapping-rain-water/
// https://leetcode.com/problems/trapping-rain-water/solutions/17357/sharing-my-simple-c-code-o-n-time-o-1-space/
#include <vector>
using namespace std;

class Answer 
{
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int res = 0;
        int left = 0, right = n-1;
        int maxL = 0, maxR = 0;

        // left <= right
        while (left < right)
        {
            // if (height[left] <= height[right])
            if (height[left] < height[right])
            {
                if (height[left] > maxL) maxL = height[left];
                else res += maxL - height[left];
                ++left;
            }   
            else
            {
                if (height[right] > maxR) maxR = height[right];
                else res += maxR - height[right];
                --right;
            }
        }        
        
        return res;
    }
};

/**
 * @note
 * Time Limit Exceeded
*/
class Fail2
{
public:
    int trap(vector<int>& height) 
    {
        int cnt = 0;
        int max = 0;
        for (int i=0; i<height.size(); ++i)
        {
            max = height[i] > max ? height[i] : max;
        }

        if (max == 0) return 0;
        
        for (int i=max; i>0; --i)
        {
            vector<int> v;
            for (int j=0; j<height.size(); ++j)
            {
                if (height[j] >= i) v.push_back(j);
            }

            if (v.size() >= 2)
            {
                for (int j=0; j<v.size()-1; ++j)
                {
                    if (v[j+1] - v[j] > 1)
                    {
                        cnt += v[j+1] - v[j] - 1;
                    }
                }
            }
        }

        return cnt;
    }
};

/**
 * @note
 * Time Limit Exceeded
*/
class Fail
{
public:
    int trap(vector<int>& height) 
    {
        int cnt = 0;

        while (true)
        {
            for (int i=0; i<height.size();)
            {
                if (height[i] == 0)
                {
                    int left=i, right=i;
                    while (left > 0 && height[left] == 0) --left;
                    while (right < height.size() && height[right] == 0) ++right;

                    if (left > 0 && right < height.size()) cnt += right - left - 1;

                    i = right+1;
                }
                else ++i;
            }

            int t;
            for (int i=0; i<height.size(); ++i)
            {
                if (height[i] != 0) height[i] -= 1;
                else ++t;
            }

            if (t == height.size()) break;
        }

        return cnt;
    }
};
