/* https://leetcode.com/problems/balanced-binary-tree
git@Pedro-Mendes */

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
    int depthCounter(TreeNode* root){
        if(root==nullptr)
            return 0;
        return 1+max(depthCounter(root->left),depthCounter(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        int depthLeft,depthRight;
        if(root==nullptr)
            return true;
        depthLeft=depthCounter(root->left);
        depthRight=depthCounter(root->right);
        if(abs(depthLeft-depthRight) <=1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
};