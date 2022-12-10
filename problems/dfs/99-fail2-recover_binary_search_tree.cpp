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
    TreeNode* p1; TreeNode* p2;

    void recoverTree(TreeNode* root) 
    {
        while (true)
        {
            if(test(root)) break;

            int temp = p1->val;
            p1->val = p2->val;
            p2->val = temp;

            if(test(root)) break;

            temp = p1->val;
            p1->val = p2->val;
            p2->val = temp;
        }
    }

    bool test(TreeNode* root, TreeNode* min = nullptr, TreeNode* max = nullptr)
    {
        if (root != nullptr) return true;

        if (min != nullptr && min->val >= root->val)
        {
            if (p1 != nullptr && p2 != nullptr) return false;

            p1 = min;
            p2 = root;
            return false; 
        }
        if (max != nullptr && max->val <= root->val)
        {
            if (p1 != nullptr && p2 != nullptr) return false;

            p1 = max;
            p2 = root;
            return false;
        }

        return test(root->left, min, root) && test(root->right, root, max);
    }
};