// https://leetcode.com/problems/longest-palindromic-substring/solutions/2923/simple-c-solution-8ms-13-lines/?orderBy=hot
// https://leetcode.com/problems/longest-palindromic-substring/description/
#include <iostream>
#include <string>
using namespace std;


class Solution 
{
public:
    Solution() = default;

    string longestPalindrome(string s) 
    {
        if(s.size() <= 1) return s;

        int max_len = 0;
        int start_idx = 0;
        int i = 0;
        int l_ptr, r_ptr;
        
        while(i < s.size()) 
        {
            l_ptr = i;
            r_ptr = i; 

            //find the middle of a palindrome
            while(r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr + 1]) ++r_ptr;

            /** @note 2번째가아닌, 1번째 while 뒤임 */
            i = r_ptr+1;

            //expand from the middle out
            while(r_ptr < s.size()-1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) 
            {
                ++r_ptr;
                --l_ptr;
            }

            int new_len = r_ptr - l_ptr + 1;
            if(new_len > max_len) 
            {
                start_idx = l_ptr;
                max_len = new_len;
            }
        }
        return s.substr(start_idx, max_len);
    }
};

int main()
{
    Solution sol;
    // cout<<sol.longestPalindrome("abcddcba");


    // cout<<sol.longestPalindrome("abccbf");
    cout<<sol.longestPalindrome("abcbf");
    // cout<<sol.longestPalindrome("abccba");
}
