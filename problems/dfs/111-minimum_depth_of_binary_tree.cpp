// https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution 
{
public:
    int minDepth(TreeNode* root) 
    {
        if (!root) return 0;
        int depth = -1;
        dfs(root, depth, 1);
        return depth;
    }

    void dfs(TreeNode* root, int& depth, int d)
    {
        if (!root) return;
        
        if (root->left == nullptr && root->right == nullptr)
        {
            if (depth == -1) depth = d;
            else depth = d < depth ? d : depth;
        }

        dfs(root->left, depth, d+1);
        dfs(root->right, depth, d+1);
    }
};
