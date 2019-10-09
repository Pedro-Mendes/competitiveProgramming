/* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/ 
git@Pedro-Mendes*/

//O(N) time and space complexity
//https://stackoverflow.com/questions/4547012/complexities-of-binary-tree-traversals/28498337
class Solution {
private:
    TreeNode* answer;
    bool preorderTraverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return false;
        bool mid = false, left = false, right = false;
        if (root == p || root == q)
            mid = true;
            
        left = preorderTraverse(root->left, p, q);
        right = preorderTraverse(root->right, p, q);
            
        if(left && mid || left && right || mid && right)
            answer = root;
        if(left || right || mid)
            return true;
        return false;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        preorderTraverse(root,p,q);
        return answer;
    }
};