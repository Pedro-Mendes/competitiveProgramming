/* https://leetcode.com/problems/minimum-depth-of-binary-tree
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
    int step=0;
    int min = -1;
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return step;
        step+=1;
        if(root->left==nullptr && root->right==nullptr){
            if(step < min || min==-1)
                min = step;
            step-=1;
            return min;
        }
        if(root->left!=nullptr)
            minDepth(root->left);
        if(root->right!=nullptr)
            minDepth(root->right);    
        step-=1;   
        return min;
    }
};