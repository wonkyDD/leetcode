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

class Answer 
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

class Fail1
{
public:
    void recoverTree(TreeNode* root) 
    {
        test(root);
    }

    bool test(TreeNode* root, TreeNode* p = nullptr, TreeNode* c = nullptr)
    {
        TreeNode* cur = root; TreeNode* prev = nullptr;
        stack<TreeNode*> stk;

        while (cur || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            
            cur = stk.top(); stk.pop();

            if (prev && prev->val >= cur->val)
            {
                if (p != nullptr && c != nullptr)
                {
                    int temp = p->val;
                    p->val = c->val;
                    c->val = temp;
                    return false;
                }

                int temp = prev->val;
                prev->val = cur->val;
                cur->val = temp;
                
                if (test(root, prev, cur))
                {
                    return true;
                }
            }

            prev = cur;
            cur = cur->right;
        }
        
        return true;
    }
};

class Fail2
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