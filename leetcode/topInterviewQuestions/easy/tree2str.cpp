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
    stringstream ss;
    string tree2str(TreeNode* t) {
        if(t==NULL){
            return "";
        }
        if(t->right == NULL && t->left==NULL){
            ss.str("");
            ss << t->val;
            string answer = ss.str();
            return answer;
        }
        if(t->right==NULL){
            ss.str("");
            ss << t->val;
            string answer = ss.str();
            return answer+"("+tree2str(t->left)+")";
        }
        ss.str("");
        ss << t->val;
        string answer = ss.str();
        return answer+"("+tree2str(t->left)+")" + "("+tree2str(t->right)+")"; 
    }
};