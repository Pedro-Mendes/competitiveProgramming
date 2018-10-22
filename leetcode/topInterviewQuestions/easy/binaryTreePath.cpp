/* https://leetcode.com/problems/binary-tree-paths/submissions/
git@Pedro-Mendes  */

class Solution {
public:
    void addPaths(vector<string> &solution, TreeNode* root, vector<int> &step){
        if(root == nullptr)
            return;
        step.push_back((root->val));
        if(root->left==nullptr && root->right==nullptr){
            string s="";
            if(!step.empty())
                s=to_string(step[0]);
            for(int i=1;i<step.size();i++){
                s+="->"+to_string(step[i]);
            }
            solution.push_back(s);
            step.pop_back();
            return;
        }
        addPaths(solution,root->left,step);
        addPaths(solution,root->right,step);
        if(!step.empty())
            step.pop_back();
        return;
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> solution;
        vector<int> step;
        addPaths(solution, root, step);
        return solution;
    }
};