/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void treeTraverse (TreeNode* root, int &nPaths, int &target) {
        if (root==nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr && target == 0)
            nPaths++;
        
        treeTraverse(root->left, nPaths, target - root->val);
        treeTraverse(root->right, nPaths, target - root->val);
    }
    
    
    int pathSum (TreeNode* root, int target) {
        int sum = 0, solution = 0;
        treeTraverse(root, solution, target);
        return solution;
    }
};

/* 
     10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1 */