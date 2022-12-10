// https://leetcode.com/problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode* root) 
    {
        vector<TreeNode*> v;
        search(root, v);

        for (int i=0; i<v.size()-1; ++i)
        {
            for (int j = i+1; j<v.size(); ++j)
            {
                int temp = v[i]->val;
                v[i]->val = v[j]->val;
                v[j]->val = temp;

                if (test(root)) return;

                temp = v[i]->val;
                v[i]->val = v[j]->val;
                v[j]->val = temp;
            }
        }
    }

    void search(TreeNode* root, vector<TreeNode*>& v)
    {
        if (root != nullptr)
        {
            search(root->left, v);
            v.push_back(root);
            search(root->right, v);
        }
    }

    bool test(TreeNode* root, TreeNode* min = nullptr, TreeNode* max = nullptr)
    {
        if (root == nullptr) return true;
        if (min != nullptr && min->val >= root->val) return false;
        if (max != nullptr && max->val <= root->val) return false;

        return test(root->left, min, root) && test(root->right, root, max);
    }
};