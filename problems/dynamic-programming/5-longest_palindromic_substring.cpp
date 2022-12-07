// https://leetcode.com/problems/longest-palindromic-substring/description/
#include <iostream>
#include <string>
using namespace std;


class Solution
{
public:
    string longestPalindrome(string s) 
    {
        int size = s.size();
        string res;
        while (size--)
        {
            int left = 0, right = size;
            while (right < s.size())
            {
                int l = left, r = right;
                while (l < r)
                {
                    if (s[l] != s[r]) break;
                    ++l; --r;
                }

                if (l >= r)
                {
                    int diff = right - left + 1;
                    res = s.substr(left, diff); 
                    goto result;
                }

                ++left; ++right;
            }
        }

        result:
            return res;
    }
};


int main()
{
    Solution sol;
    // cout<<sol.longestPalindrome("asdfabafjfj");
    // cout<<sol.longestPalindrome("asdf");
    // cout<<sol.longestPalindrome("cbbd");
    // cout<<sol.longestPalindrome("cbbddbbc");
    cout<<sol.longestPalindrome("babad");
}
