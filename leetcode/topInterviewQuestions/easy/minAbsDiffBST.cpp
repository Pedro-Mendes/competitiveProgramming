class Solution {
public:
    void DFS(TreeNode* root, vector<int> &nodes){
        if(root==nullptr)
            return;
        DFS(root->left,nodes);
        nodes.push_back(root->val);
        DFS(root->right,nodes);
    }
    
    
    int getMinimumDifference(TreeNode* root) {
        int minimum = INT_MAX;
        vector<int> nodes;
        DFS(root,nodes);
        for(int i=1; i<nodes.size();i++){
            minimum = min(minimum, nodes[i]-nodes[i-1]);
        }
        if(minimum==INT_MAX)
            return 0;
        return minimum;
    }
};

/* Optimized solution */

class Solution {
public:
    void DFS(TreeNode* root, int &minimum, int &last){
        if (root==nullptr)
            return;
        DFS (root->left,minimum,last);
        if (last==-1){
            last = root->val;
        }else{
            minimum = min(minimum, root->val - last);
            last = root->val;
        }
        DFS (root->right,minimum,last);
    }
    
    
    int getMinimumDifference(TreeNode* root) {
        int minimum = INT_MAX;
        int last=0;
        DFS (root,minimum,last);
        return minimum;
    }
};

/* Better yet */

