/* https://leetcode.com/problems/path-sum-iii/
git@Pedro-Mendes */
class Solution {
public:
    int pathSum (TreeNode* root, int target) {
        int paths = 0;
        DFS(root, target, paths);
        return paths;
    }
private:
    void DFS (TreeNode* root, const int target, int &paths) {
        if(root == nullptr)
            return;
        checkSum(root, target, paths);
        DFS(root->left, target, paths);
        DFS(root->right, target, paths);
    }
    
    void checkSum (TreeNode* root, int target, int &paths) {
        if (root == nullptr)
            return;
        if (target - root->val == 0) {
            paths++;
        }
        checkSum (root->left, target - root->val, paths);
        checkSum (root->right, target - root->val, paths);
  