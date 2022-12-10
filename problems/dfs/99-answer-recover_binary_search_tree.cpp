// https://leetcode.com/problems/recover-binary-search-tree/
// https://leetcode.com/problems/recover-binary-search-tree/solutions/322282/recover-binary-search-tree/
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
    TreeNode *x = nullptr, *y = nullptr, *pred = nullptr;
    // TreeNode* y = nullptr;
    // TreeNode* pred = nullptr;

    void recoverTree(TreeNode *root) 
    {
        findTwoSwapped(root);
        swap(x, y);
    }
    
    /**
     * @note
     * 스택 or 벡터에 TreeNode를 순회하면서 넣어오는 과정과
     * 바뀐 노드를 찾는 과정을 분리하지 않고 하나로 합치기
    */
    void findTwoSwapped(TreeNode *root)
    {
        if (root == nullptr) return;

        findTwoSwapped(root->left);
        if (pred != nullptr && pred->val > root->val)
        {
            y = root;

            if (x == nullptr) x = pred;
            else return;
        }

        pred = root;
        findTwoSwapped(root->right);
    }

    void swap(TreeNode *x, TreeNode *y)
    {
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
};