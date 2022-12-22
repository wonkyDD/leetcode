// https://leetcode.com/problems/symmetric-tree/
// https://leetcode.com/problems/symmetric-tree/solutions/33089/my-c-accepted-code-in-16ms-with-iteration-solution/?orderBy=most_votes
#include <vector>
#include <queue>
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

/**
 * @note
 * solve iteratively
*/
class Answer
{
public:
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *left, *right;
        if (!root) return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        
        while (!q1.empty() && !q2.empty())
        {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;
            if (left->val != right->val) return false;
                
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        
        return true;
    }
};

/**
 * @note
 * solve recursively
*/
class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        vector<TreeNode*> v;
        v.push_back(root);
        return bfs(v);
    }

    bool bfs(vector<TreeNode*> v)
    {
        int cnt = 0;
        vector<TreeNode*> c;
        for (int i=0; i<v.size(); ++i)
        {
            if (v[i] == nullptr) ++cnt;
            else
            {
                c.push_back(v[i]->left);
                c.push_back(v[i]->right);
            }
        }

        if (cnt == v.size()) return true;

        int left = 0, right = c.size()-1;
        while (left < right)
        {
            if (c[left] == nullptr || c[right] == nullptr)
            {
                if (c[left] != nullptr || c[right] != nullptr) return false;
            }
            else if (c[left]->val != c[right]->val) return false;
            
            ++left;
            --right;
        }

        return bfs(c);
    }
};

class Fail 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        vector<int> v;
        inorder(root, v);

        int l, r;
        for (int i=0;; ++i)
        {
            l = i; 
            r = v.size() - i - 1;
            if (l >= r) break;

            if (v[l] != v[r]) return false;
        }

        return true;
    }

    void inorder(TreeNode* root, vector<int>& v)
    {
        if (root == nullptr) return;

        if (root->left != nullptr || root->right != nullptr)
        {
            if (root->left == nullptr) v.push_back(-101);
            // if (root->right == nullptr) v.push_back(-101);
        }

        inorder(root->left, v);
        v.push_back(root->val);

        if (root->left != nullptr || root->right != nullptr)
        {
            // if (root->left == nullptr) v.push_back(-101);
            if (root->right == nullptr) v.push_back(-101);
        }
        inorder(root->right, v);
    }
};
