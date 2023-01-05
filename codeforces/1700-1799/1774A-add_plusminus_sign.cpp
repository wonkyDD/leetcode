// https://codeforces.com/contest/1774/problem/A
// https://codeforces.com/blog/entry/110184
#include <bits/stdc++.h>
using namespace std;

namespace Answer
{
/** @note 2≤n≤100, why 1005? */
// char c[100];
char c[1005];
int main()
{
    int t;
    scanf("%d", &t);
    int n;
    while (t--)
    {
        scanf("%d", &n);
        /**
         * @note
         * - c+1 : start from idx 1, not 0
         * - reuse array `c`
        */
        scanf("%s", c + 1);
        
        // We can get that by adding '-' before the 2nd,4th,⋯,2k-th 1, and '+' before the 3rd,5th,⋯,2k+1-th 1.
        int u = 0;
        for (int i = 1; i <= n; ++i)
        {
            bool fl = (c[i] == '1') && u;
            /** @note type conversion from char to int by arithmetic evaluation */
            u ^= (c[i] - '0');
            if (i != 1) putchar(fl ? '-' : '+');
        }

        putchar('\n');
    }
    return 0;
}
} // namespace Answer

namespace Solution
{
int main()
{
    int t,n; string s; char c;
    cin>>t;
    while(t--)
    {
        s = "";
        cin>>n;
        for (int i=0; i<n; ++i)
        {
            cin>>c;
            s+=c;
        }
        /** @todo clear istream */
        while (cin.get() != '\n') {};

        int cnt = s[0] == '1' ? 1 : 0;
        for (int i=1; i<s.size(); ++i)
        {
            if (cnt > 0 && s[i] == '1')
            {
                s[i] = '-';
                --cnt;
            }
            else
            {
                if(s[i] == '1') ++cnt;
                s[i] = '+';
            }
        }

        cout<<s.substr(1, s.size()-1)<<'\n';
    }
    return 0;
}
} // namespace Solution
