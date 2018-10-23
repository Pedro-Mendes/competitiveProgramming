/* https://leetcode.com/problems/path-sum/submissions/
git@Pedro-Mendes */

class Solution {
public:
    void traverse(TreeNode* root, int sum, int stepSum, bool &answer){
        if(root==nullptr || answer==true)
            return;
        stepSum+=root->val;
        if(stepSum == sum && root->left==nullptr && root->right==nullptr)
            answer=true;
        traverse(root->left,sum,stepSum,answer);
        traverse(root->right,sum,stepSum,answer);
        stepSum-=root->val;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        bool answer = false;
        traverse(root,sum,0,answer);
        return answer;
    }
};