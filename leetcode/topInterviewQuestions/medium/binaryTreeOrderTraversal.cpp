/* https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/
git@Pedro-Mendes */

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
    void BFS(TreeNode* root, vector<vector<int>> &answer, int &i){
        if(root == nullptr){
            return;            
        }
        if(i >= answer.size())
            answer.push_back(vector<int> ());
        answer[i].push_back(root->val);
        i+=1;
        BFS(root->left,answer,i);
        BFS(root->right,answer,i);
        i-=1;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        int i =0;
        BFS(root,answer,i);
        /*for(int j =0; j<answer.size();j++){
            for(int k =0; k<answer[j].size();k++){
                cout << answer[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
            return answer;
    }
};