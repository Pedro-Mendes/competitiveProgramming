/* https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/ 
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
public:
    void depth(int &max, TreeNode * root, int i){
        if(root != NULL){
            i+=1;
            if(i> max){
                max = i;
            }
            depth(max,root->left,i);
            depth(max,root->right,i);
        }
    }
    
    int maxDepth(TreeNode* root) {
        int max = 0;
        depth(max,root,0);
        return max;
    }
};