/*https://leetcode.com/problems/kth-smallest-element-in-a-bst/
git@Pedro-Mendes*/

/*O(k) time compleity, O(1) space complexity*/
class Solution {
private: 
    void traverse(TreeNode *root, int &k, int &answ) {
        if (root) {
            traverse(root->left,k, answ);
            k--;
             if (k == 0)
                answ = root->val;
            traverse(root->right,k, answ);
        }
}
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int solution;
        traverse(root, k, solution);
        return solution;
    }
};