// https://leetcode.com/problems/recover-binary-search-tree/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        test(root);
    }

    bool test(TreeNode* root, TreeNode* p = nullptr, TreeNode* c = nullptr)
    {
        TreeNode* cur = root; TreeNode* prev = nullptr;
        stack<TreeNode*> stk;

        while (cur || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            
            cur = stk.top(); stk.pop();

            if (prev && prev->val >= cur->val)
            {
                if (p != nullptr && c != nullptr)
                {
                    int temp = p->val;
                    p->val = c->val;
                    c->val = temp;
                    return false;
                }

                int temp = prev->val;
                prev->val = cur->val;
                cur->val = temp;
                
                if (test(root, prev, cur))
                {
                    return true;
                }
            }

            prev = cur;
            cur = cur->right;
        }
        
        return true;
    }
};