// https://leetcode.com/problems/balanced-binary-tree/
// https://leetcode.com/problems/balanced-binary-tree/solutions/35691/the-bottom-up-o-n-solution-would-be-better/
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Answer
{
public:
    int dfs (TreeNode *root) 
    {
        if (root == nullptr) return 0;

        int left = dfs(root->left);
        if (left == -1) return -1;
        int right = dfs(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }

    bool isBalanced (TreeNode *root) 
    {
        return dfs(root) != -1;
    }
};

class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        return dfs(root);
    }

    void getDepth(TreeNode* root, int& max, int d)
    {
        if (root == nullptr) return;

        max = d > max ? d : max;
        getDepth(root->left, max, d+1);
        getDepth(root->right, max, d+1);
    }

    bool dfs(TreeNode* root)
    {
        if (root == nullptr) return true;
        
        int maxL=0, maxR=0;
        getDepth(root->left, maxL, 1);
        getDepth(root->right, maxR, 1);

        if (abs(maxL-maxR) > 1) return false;
        return dfs(root->left) && dfs(root->right);
    }
};
