/* https://leetcode.com/problems/binary-tree-tilt/
git@Pedro-Mendes */

class Solution {
public:
    int sumNodes(TreeNode* root) {
        if (root==nullptr)
            return 0;
        return root->val + sumNodes(root->right) + sumNodes(root->left);
    }
    
    int tilt (TreeNode* root) {
        if (root == nullptr)
            return 0;
        return abs(sumNodes(root->right)-sumNodes(root->left));
    }
    
    int findTilt (TreeNode* root) {
        if (root==nullptr)
            return 0;
        return tilt(root)+findTilt(root->left)+findTilt(root->right);
    }
};

/*Optimization*/

class Solution {
public:
    int sumNodes(TreeNode* root, int &tilt) {
        if (root==nullptr)
            return 0;
        int sumRight = sumNodes(root->right,tilt);
        int sumLeft = sumNodes(root->left,tilt);
        tilt += abs(sumRight-sumLeft);
        return root->val + sumRight + sumLeft;
    }
    
    int findTilt (TreeNode* root) {
        if (root==nullptr)
            return 0;
        int tilt = 0;
        tilt+= abs(sumNodes(root->left,tilt)-sumNodes(root->right,tilt));
        return tilt;
    }
};