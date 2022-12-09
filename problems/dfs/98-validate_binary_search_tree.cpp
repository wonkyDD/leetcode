// https://leetcode.com/problems/validate-binary-search-tree/
#include <iostream>
#include <vector>
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
    bool res = true;

    bool isValidBST(TreeNode* root) 
    {
        dfs(root, NULL, NULL);
        return res;
    }

    // floor, cell 표현이 더 적절할듯
    void dfs(TreeNode* root, const int _min, const int _max)
    {
        if (root != nullptr)
        {
            if ((_min != NULL && root->val <= _min) || (_max != NULL && root->val >= _max))
            {
                res = false;
                return;
            }


            // left 노드처리
            int min, max;
            if (root->left != nullptr)
            {
                if (root->left->val < root->val) max = root->val;

                else
                {
                    res = false;
                    return;
                }
            }
            dfs(root->left, _min, max);


            // right 노드처리
            if (root->right != nullptr)
            {
                if (root->right->val > root->val) min = root->val;

                else
                {
                    res = false;
                    return;
                }
            }
            dfs(root->right, min, _max);
        }
    }
};