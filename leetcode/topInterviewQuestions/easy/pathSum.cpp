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

/*Awesome solution by karan14
https://leetcode.com/problems/path-sum/discuss/182269/C%2B%2B-using-recursion-beats-100*/

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
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(!root)
            return false;
        if(!root->left && !root->right && sum==root->val)
            return true;
            
        if(root->left && root->right)
        {
            return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val);
        }
        else if(!root->right){
            return hasPathSum(root->left,sum - root->val);}
        else if(!root->left){
            return hasPathSum(root->right,sum - root->val);
        }
        
       
        
        
        return false;
        
        
    }
};