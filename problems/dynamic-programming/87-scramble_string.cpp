// https://leetcode.com/problems/scramble-string/
// https://leetcode.com/problems/scramble-string/solutions/29469/c-solutions-w-explanation-both-recursive-and-top-down-dynamic-programming/
#include <bits/stdc++.h>
using namespace std;

class Answer
{
public:
    string s1, s2;
    hash<string> hash;
    // unordered_map<size_t, bool> cache;
    unordered_map<int, bool> cache;

    bool isScramble(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        // if (s1 == s2) return true;
        // if (m != n) return false;
        
        // if (m == 0 || n == 0) return false;
        this->s1 = s1;
        this->s2 = s2;

        return fn(0, m-1, 0, n-1);
    }

    bool fn(int s1s, int s1e, int s2s, int s2e)
    {
        // hashing; do not use `length`
        string hash_str = s1.substr(s1s, s1e-s1s+1) + "#" + s2.substr(s2s, s2e-s2s+1);
        auto it = cache.find(hash(hash_str));
        if (it != cache.end()) return it->second;

        bool res = false;
        int length = s1e - s1s + 1;
        if ((s1e-s1s) != (s2e-s2s)) res = false;
        // else if (s1e < s1s || s2e < s2s) res = false;
        else if (s1.substr(s1s, length) == s2.substr(s2s, length)) res = true;
        // else if (s1e == s1s) res = s1[s1s] == s2[s2s];
        else
        {
            // scramble
            // for (int k=0; k<length; ++k)
            // for (int k=0; k<length-1; ++k)
            for (int k=0; k<s1e-s1s; ++k)
            {
                // if (fn(s1s, s1s+k, s2s, s2s+k) && fn(s1s+k, s1e, s2s+k, s2e)) res = true;
                // if (fn(s1s, s1s+k, s2s+k, s2e) && fn(s1s+k, s1e, s2s, s2s+k)) res = true;

                if (fn(s1s, s1s+k, s2s, s2s+k) && fn(s1s+k+1, s1e, s2s+k+1, s2e)) res = true;
                if (fn(s1s, s1s+k, s2e-k, s2e) && fn(s1s+k+1, s1e, s2s, s2e-k-1)) res = true;
            }
        }

        cache[hash(hash_str)] = res;
        return res;
    }
};

/**
 * @note Time Limit Exceeded
*/
class SolutionFail
{
public:
    string s1, s2;
    // hash?

    bool isScramble(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        // if (s1 == s2) return true;
        // if (m != n) return false;
        
        // if (m == 0 || n == 0) return false;
        this->s1 = s1;
        this->s2 = s2;

        return fn(0, m-1, 0, n-1);
    }

    bool fn(int s1s, int s1e, int s2s, int s2e)
    {
        if ((s1e-s1s) != (s2e-s2s)) return false;
        // if (s1e < s1s || s2e < s2s) return false;
        int length = s1e - s1s + 1;
        if (s1.substr(s1s, length) == s2.substr(s2s, length)) return true;
        
        // scramble
        // for (int k=0; k<length; ++k)
        // for (int k=0; k<length-1; ++k)
        for (int k=0; k<s1e-s1s; ++k)
        {
            // if (fn(s1s, s1s+k, s2s, s2s+k) && fn(s1s+k, s1e, s2s+k, s2e)) return true;
            // if (fn(s1s, s1s+k, s2s+k, s2e) && fn(s1s+k, s1e, s2s, s2s+k)) return true;

            if (fn(s1s, s1s+k, s2s, s2s+k) && fn(s1s+k+1, s1e, s2s+k+1, s2e)) return true;
            if (fn(s1s, s1s+k, s2e-k, s2e) && fn(s1s+k+1, s1e, s2s, s2e-k-1)) return true;
        }

        return false;
    }
};

class Fail
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() == 1) return s1==s2;
        if (s1 == s2) return true;

        for (int i=0; i<s1.size(); ++i)
        {
            /** @note error: cant merge substring after division */
            string ns = s1.substr(i, s1.size()-i) + s1.substr(0, i);
            
            for (int j=1; j<ns.size(); ++j)
            {
                if ((isScramble(ns.substr(0, j), s2.substr(0, j)) &&
                isScramble(ns.substr(j, ns.size()-j), s2.substr(j, s2.size()-j))) ||
                (isScramble(ns.substr(0, j), s2.substr(j, s2.size()-j)) &&
                isScramble(ns.substr(j, ns.size()-j), s2.substr(0, j))))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
