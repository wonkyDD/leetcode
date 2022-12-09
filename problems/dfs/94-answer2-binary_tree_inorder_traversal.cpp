// https://leetcode.com/problems/binary-tree-inorder-traversal/
// https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/127563/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        stack<TreeNode*> stk;
        TreeNode* cur = root;

        while (cur != nullptr || !stk.empty())
        {
            while (cur != nullptr)
            {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();
            v.push_back(cur->val);
            cur = cur->right;
        }

        return v;
    }
};