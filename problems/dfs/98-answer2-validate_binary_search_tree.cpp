// https://leetcode.com/problems/validate-binary-search-tree/
// https://leetcode.com/problems/validate-binary-search-tree/solutions/204551/validate-binary-search-tree/
#include <iostream>
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

class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        if (root == nullptr) return true;
        
        stack<TreeNode*> s;
        TreeNode* current = root; TreeNode* prev = nullptr;
        while (current || !s.empty())
        {
            while(current)
            {
                s.push(current);
                current = current->left;
            }
            
            current = s.top(); s.pop();

            /**
             * @note
             * inorder-traversal의 특징을 이용.
             * 
             * a<x<b 의 not은 a>=x>=b 이니까
             * prev를 a->x->b 위치로 이동시키면
             * prev->val >= current->val 처럼
             * 쉽게 비교연산이 가능해진다는 idea.
             * 
             * ex) a: prev, x: cur
             * ex) x: prev, b: cur->right (cur)
            */
            if (prev && prev->val >= current->val) return false;
            prev = current;
            current = current->right;
        } 
        return true;
    }
};