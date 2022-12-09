// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
        TreeNode* leaf = root;
        stack<TreeNode*> stk;
        vector<int> v;

        while (true)
        {
            while (leaf->left != nullptr)
            {
                stk.push(leaf);
                leaf = leaf->left;
            }

            // v.push_back(leaf->val);
            while (leaf->right == nullptr)
            {
                // goto 쓰기
                if (leaf == root) break; 

                v.push_back(leaf->val);
                leaf = stk.top();
                stk.pop();
            }

            // goto 쓰기
            if (leaf == root && leaf->right == nullptr) break;

            leaf = leaf->right;

        }

        return v;
    }
};


int main()
{
}