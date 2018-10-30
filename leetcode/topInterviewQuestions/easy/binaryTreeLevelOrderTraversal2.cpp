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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector< vector<int> > solution;
        BFS(root, 0, solution);
        reverse(solution.begin(),solution.end());
        return solution;
    }
    
private:
    void BFS (TreeNode* root, int level, vector< vector<int> > &solution) {
        if (root == nullptr)
            return;
        if (level >= solution.size())
            solution.push_back( vector<int> ());
        BFS(root->left, level+1, solution);
        BFS(root->right, level+1, solution);
        solution[level].push_back(root->val);
    }
};