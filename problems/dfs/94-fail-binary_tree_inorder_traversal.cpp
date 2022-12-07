// https://leetcode.com/problems/binary-tree-inorder-traversal/ 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */     
 

struct Node {
    int val;
    bool found;
    vector<Node*> linked;
    Node(int x) : val(x), found(false) {}
};  
int cnt = 0;
void dfs (Node* first);

int main() {
    int n, pair;
    vector<Node> nodes;
    cin>>n;
    cin>>pair;
    
    // node 생성
    for (int i=0; i<n; ++i) {
        Node n = Node(i+1);
        nodes.push_back(n);
    }

    // 연결된 주소들 node별 삽입
    int a,b;
    for (int i=0; i<pair; ++i) {
        cin>>a>>b;
        nodes[a-1].linked.push_back(&nodes[b-1]);
        nodes[b-1].linked.push_back(&nodes[a-1]);
    }

    dfs(&nodes[0]);
    cout<<cnt;
}

void dfs (Node* first) {
    auto linked = first->linked;
    for (auto it=linked.begin(); it!=linked.end(); ++it) {
        bool found = (*it)->found;
        if (!found) {
            (*it)->found = true;
            cnt++;
            dfs(*it);
        }
        else break;
    }
}