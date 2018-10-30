
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
        if (target == 0)
            paths++; 
        if (root == nullptr)
            return;
        checkSum (root->left, target - root->val, paths);
        checkSum (root->right, target - root->val, paths);
    }
};