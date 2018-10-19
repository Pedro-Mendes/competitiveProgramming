/* https://leetcode.com/problems/symmetric-tree/ 
git@Pedro-Mendes*/

class Solution {
public:
    stringstream ss;
    string in;
    void travLeft(TreeNode* root, vector<string> &nodes){
        if(root == nullptr){
            nodes.push_back("");
            return;
        }else{
            ss.str("");
            //cout << "val = " << root->val << endl;
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
            travRight(root->right,nodes,i,answer);
            travRight(root->left,nodes,i,answer);    
        }
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }else if((root->right == nullptr && root->left) || (root->left == nullptr && root->right)){
            return false;
        }else{
            int i=0;
            vector<string> nodes;
            bool answer = true;
            travLeft(root->left, nodes);
            //for(int j=0; j<nodes.size();j++)
                //cout << nodes[j] << " ";
            //cout << endl;
            travRight(root->right, nodes,i,answer);
            if(i<nodes.size()-1){
                return false;
            }
            return answer;    
        }
        
    }
};


/* Optimized solution*/

class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val)
            && isMirror(t1->right, t2->left)
            && isMirror(t1->left, t2->right);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};