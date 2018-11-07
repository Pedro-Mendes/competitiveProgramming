/* https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
git@Pedro-Mendes */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _chil_childrendren;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int maxDepth = 0;
        DFS(root, 1, maxDepth);
        return maxDepth;
    }
    
private: 
    void DFS(Node* root, int depth, int &maxDepth) {
        if(root==nullptr)
            return;
        maxDepth = max(depth, maxDepth);
        for(int i=0;i<root->children.size();i++){
            DFS(root->children[i], depth+1, maxDepth);
            }
        }
};