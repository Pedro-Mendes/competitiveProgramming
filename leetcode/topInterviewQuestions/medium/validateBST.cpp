/* https://leetcode.com/problems/validate-binary-search-tree/
git@Pedro-Mendes */

class Solution {
public:
    bool isBST(TreeNode* root, TreeNode* &last){
        if(root==nullptr)
            return true;
        bool leftBST = isBST(root->left, last);
        if(last == nullptr){
            last = new TreeNode(root->val);
        }else{
            if(root->val <= last->val){
                return false;
            }
            last->val = root->val;
        }
        if(leftBST==false){
            return false;
        }
        bool rightBST = isBST(root->right, last);
        return leftBST && rightBST;
    }
    
    bool isValidBST(TreeNode* root) {
            TreeNode* last = nullptr;
            return isBST(root,last);
    }
};