/* https://leetcode.com/problems/average-of-levels-in-binary-tree/submissions/ 
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
    void average(vector<double> &sum,vector<int> &count, int i, TreeNode* root){
        if(root == NULL){
            return;
            cout << "test" << endl;
        }else{
            if(i>(int)sum.size()-1){
                sum.push_back(root ->val);
                count.push_back(1);
            }else{
                sum[i] += root->val;
                count[i] ++;
            }
            average(sum,count,i+1,root->left);
            average(sum,count,i+1,root->right);
        }
        
    } 
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> count;
        vector<double> sum;
        int i =0;
        average(sum,count,i,root);
        for(int j=0; j<sum.size();j++){
            sum[j] /= count[j];
        }
        return sum;
    }
};