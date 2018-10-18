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
    void swap(TreeNode *t1, TreeNode *t2, TreeNode *root){
        if(t1 != NULL && t2!= NULL){
            int tmp;
            tmp = t1->val;
            t1->val = t2->val;
            t2->val = tmp;
            
            TreeNode *m = new TreeNode(t2->val);
            m ->right = t2->right;
            m->left = t2->left;
            
            t2->right = t1->right;
            t2->left = t1->left;
            
            t1->right = m->right;
            t1->left = m->left;
            
            
        }else if(t1 == NULL && t2!=NULL){
            t1 = new TreeNode(t2->val);
            t1->right = t2->right;
            t1->left = t2->left;
            t2 = NULL;
            root ->left = t1;
            root ->right = NULL;
        }else if(t1 != NULL && t2 ==NULL){
            t2 = new TreeNode(t1->val);
            t2->right = t1->right;
            t2->left = t1->left;
            t1 = NULL;
            root ->left = NULL;
            root ->right = t2;
        }else{
            /*both null*/
        }
    }
        
    
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *head = root;
        if(root != NULL){
            swap(root->left,root->right, root);
            invertTree(root->left);
            invertTree(root->right);
        }
        return head;
    }
};