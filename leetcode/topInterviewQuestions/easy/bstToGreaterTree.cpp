/*https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/
git@Pedro-Mendes*/

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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root!=NULL){
            convertBST(root->right);
            root->val += sum;
            sum = root-> val;
            convertBST(root->left);
        }
        return root;
    }
};