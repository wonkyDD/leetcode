// Templates for dfs

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
 * @todo 꼭 github, PS 갤러리에 가서 질문할것
 * 
 * 99-recover_binary_search_tree (https://leetcode.com/problems/recover-binary-search-tree/)
 * 
*/