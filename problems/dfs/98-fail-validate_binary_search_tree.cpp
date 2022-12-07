// https://leetcode.com/problems/validate-binary-search-tree/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        // 매번 max와 min을 전달해줘야함
        // 갱신하면서 left, right이 min max사이에있는지 조사
        
        // left방향에 대해서는 max를 leftval로 갱신후에 조사
        // right은 min을 rightval로 갱신후에 조사

        // 이전에 했던방식으로 down-way하면서 
        // 매 노드에 대해 조사하면 됨
        return true;
    }
};

// class Solution {
// public:
//     bool isValid = true;
    
//     bool isValidBST(TreeNode* root) {
//         check(nullptr, root);
//         return this->isValid;
//     }
    
//     void check(TreeNode* parent, TreeNode* cur) {
//         if (!this->isValid) return;
        
//         else {
//             TreeNode* left = cur->left;
//             TreeNode* right = cur->right;
//             bool isLeft;
            
//             // root인 경우 nullptr 참조에러
//             if (parent != nullptr) {
//                 isLeft = parent->left == cur ? true : false;
//                 this->isValid = isLeft ? (parent->val > cur->val) : (parent->val < cur->val);

//                 if (!this->isValid) return;
//             }
            
//             if (left != nullptr) check(cur, left);
//             if (right != nullptr) check(cur, right);
            
//             // 역추적하면서 parent == nullptr까지 당위성 조사
//             if (left==nullptr && right==nullptr) {
//                 TreeNode* temp = nullptr;
//                 while (true) {
//                 }
//             }
//         }
//     }
// };