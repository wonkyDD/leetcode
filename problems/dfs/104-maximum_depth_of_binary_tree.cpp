// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) 
    {
        int max = 0;
        dfs(root, max, 1);
        return max;
    }

    void dfs(TreeNode* root, int& max, int d)
    {
        if (root == nullptr) return;

        max = d > max ? d : max;
        dfs(root->left, max, d+1);
        dfs(root->right, max, d+1);
    }
};
