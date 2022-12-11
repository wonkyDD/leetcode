// https://leetcode.com/problems/same-tree/
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
    bool res = true;

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        inorder(p, q);
        return res;
    }

    void inorder(TreeNode* r1, TreeNode* r2)
    {
        if (r1 == nullptr || r2 == nullptr)
        {
            if (r1 != nullptr || r2 != nullptr) res = false;
            return;
        }

        inorder(r1->left, r2->left);
        if (r1->val != r2->val)
        {
            res = false;
            return;
        }
        inorder(r1->right, r2->right);
    }
};