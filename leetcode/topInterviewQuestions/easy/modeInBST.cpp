/* https://leetcode.com/problems/find-mode-in-binary-search-tree/description/ 
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
    int max=-1;
    void frequencies(TreeNode* root, map<int,int> &hash){
        if(root==nullptr)
            return;
        hash[root->val]+=1;
        if(hash[root->val]>max)
            max = hash[root->val];
        frequencies(root->left,hash);
        frequencies(root->right,hash);
    }
    
    void add2Vector(TreeNode* root, map<int,int> &hash, vector<int> &answer){
        if(root==nullptr)
            return;
        if(hash[root->val] >= max){
            max = hash[root->val];
            hash[root->val] = -1;
            answer.push_back(root->val);
        }
        add2Vector(root->left, hash, answer);
        add2Vector(root->right, hash, answer);
    }
    
    vector<int> findMode(TreeNode* root) {
        map<int,int> hash;
        frequencies(root,hash);
        vector<int> answer;
        add2Vector(root, hash, answer);
        return answer;
    }
};