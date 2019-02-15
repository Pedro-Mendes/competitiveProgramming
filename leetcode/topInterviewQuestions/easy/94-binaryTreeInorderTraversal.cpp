/*https://leetcode.com/problems/binary-tree-inorder-traversal
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
private:
    void inOrder(TreeNode* root, vector<int> &solution) {
        if (!root)
            return;
        inOrder(root->left, solution);
        solution.push_back(root->val);
        inOrder(root->right, solution);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> solution;
        inOrder(root, solution);
        return solution;
    }
};