/*https://leetcode.com/problems/delete-nodes-and-return-forest/
git@Pedro-Mendes*/

/*O(N) time and space complexity*/
class Solution {
private:
    void deleteNodes(TreeNode* &root, unordered_map<int,bool> &deleted, vector<TreeNode*> &output) {
        if (!root)
            return;
        deleteNodes(root->left, deleted, output);
        deleteNodes(root->right, deleted, output);
        if (deleted[root->val]) {
            if(root->left)
                output.push_back(root->left);
            if(root->right)
                output.push_back(root->right);
            root = nullptr;
        }   
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,bool> deleted;
        for (int i = 0; i < to_delete.size(); i++) {
            deleted[to_delete[i]] = true;
        }
        vector<TreeNode*> output;
        deleteNodes(root,deleted,output);
        if(root)
            output.push_back(root);
        return output;
    }   
};