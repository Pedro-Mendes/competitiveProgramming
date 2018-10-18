/* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == nullptr || q == nullptr)
            return nullptr;
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root -> right,p,q);
        }else if((p->val <= root->val && q->val >= root->val) || (p->val >= root->val && q->val <= root->val)){
            return root;
            
        }else {
            return lowestCommonAncestor(root -> left,p,q);
        }
    }
};
