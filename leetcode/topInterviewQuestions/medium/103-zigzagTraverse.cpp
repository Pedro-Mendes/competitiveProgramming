/*https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
git@Pedro-Mendes*/

class Solution {
private:
    vector<vector<int>> answ;
    void zigzagTraverse(TreeNode* root, int level) {
            if(!root)
                return;
            if(answ.size() <= level)
                answ.push_back(vector<int> ());
            if(level%2 != 0) {
                answ[level].insert(answ[level].begin(),root->val);
            } else {
                answ[level].push_back(root->val);
            }
            zigzagTraverse(root->left, level+1);
            zigzagTraverse(root->right, level+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzagTraverse(root, 0);
        return answ;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answ;
        if(!root)
            return answ;
        int level = 0, answSize;
        TreeNode* tmp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            if(answ.size() <= level)
                answ.push_back(vector<int> (q.size()));
            answSize = answ[level].size();
            for(int i = 0; i < answSize; i++) {
                tmp = q.front();
                q.pop();
                if (level%2) {
                    answ[level][answSize - i - 1] = tmp->val;

                } else {
                    answ[level][i] = tmp->val;
                }
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            level++;
        }
        return answ;
    }
};