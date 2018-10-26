/*https://leetcode.com/problems/diameter-of-binary-tree/
git@Pedro-Mendes*/

class Solution {
public:
    int nodeCount (TreeNode* root, int &maxDiameter) {
        if (root == nullptr)
            return 0;
        int diameterLeft = nodeCount(root->left,maxDiameter);
        int diameterRight = nodeCount(root->right,maxDiameter);
        maxDiameter = max(diameterRight+diameterLeft+1,maxDiameter);
        return max(diameterLeft,diameterRight)+1;
    }
    
    int diameterOfBinaryTree (TreeNode* root) {
        int maxDiameter = 1;
        nodeCount(root,maxDiameter);
        return maxDiameter-1;
    }
};