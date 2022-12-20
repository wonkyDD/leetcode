// https://leetcode.com/problems/binary-tree-inorder-traversal/
// https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/127563/binary-tree-inorder-traversal/
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

class Answer1
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        helper(root, v);
        return v;
    }

    void helper(TreeNode* root, vector<int>& v)
    {
        if (root != nullptr)
        {
            helper(root->left, v);
            v.push_back(root->val);
            helper(root->right, v);
        }
    }
};

class Answer2
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

class Fail 
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