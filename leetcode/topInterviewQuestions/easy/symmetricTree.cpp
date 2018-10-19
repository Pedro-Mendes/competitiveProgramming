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
    string in;
    void travLeft(TreeNode* root, vector<string> nodes){
        if(root == nullptr){
            nodes.push_back("");
            return;
        }else{
            ss.str("");
            ss << root->val;
            in = ss.str();
            nodes.push_back(in);
            travLeft(root->left,nodes);
            travLeft(root->right,nodes);
        }
    }
    void travRight(TreeNode* root, vector<string> nodes, int &i, bool &answer){
        if(root == nullptr){
            i+=1;
            return;
        }else{
            ss.str("");
            ss << root->val;
            in = ss.str();
            if(in != nodes[i]){
                answer = false;
                return;
            }
            i+=1;
            travLeft(root->right,nodes);
            travLeft(root->left,nodes);    
        }
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }else{
            int i=0;
            vector<string> nodes;
            bool answer = true;
            travLeft(root->left, nodes);
            travRight(root->right, nodes,i,answer);
            return answer;    
        }
        
    }
};
