// https://leetcode.com/problems/validate-binary-search-tree/
// https://leetcode.com/problems/validate-binary-search-tree/solutions/204551/validate-binary-search-tree/
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

class Answer1 
{
public:
    bool isValidBST(TreeNode* root, TreeNode* min=nullptr, TreeNode* max=nullptr) 
    {
        if (!root) return true;
        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};

class Answer2
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