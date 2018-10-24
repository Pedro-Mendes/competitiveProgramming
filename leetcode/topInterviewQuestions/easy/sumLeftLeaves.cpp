class Solution {
public:
    void traverseTree(TreeNode *root, int &sum, int side){
        if(root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr && side==0) {
            sum+=root->val;
            return;
        }
        traverseTree(root->left, sum, 0);
        traverseTree(root->right, sum, 1);
        
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traverseTree(root,sum,-1);
        return sum;
    }   
};