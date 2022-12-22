// https://leetcode.com/problems/path-sum/
// https://leetcode.com/problems/path-sum/solutions/36367/3-lines-of-c-solution/

class Answer
{
public:
    bool hasPathSum(TreeNode *root, int targetSum) 
    {
        if (root == nullptr) return false;
        if (root->val == targetSum && root->left ==  nullptr && root->right == nullptr) return true;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};

class Solution 
{
public:
    int targetSum;
    bool res = false;

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        this->targetSum = targetSum;
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int sum)
    {
        if (!root) return;

        if (root->left == nullptr && root->right == nullptr)
        {
            if (targetSum == sum + root->val)
            {
                res = true;
                return;
            }
        }

        dfs(root->left, sum + root->val);
        dfs(root->right, sum + root->val);
    }
};
