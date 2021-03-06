/* https://leetcode.com/problems/subtree-of-another-tree/
git@Pedro-Mendes */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == nullptr && q!=nullptr) || (q == nullptr && p!=nullptr))
            return false;
        if(p == nullptr && q==nullptr)
            return true;
        if(p->val != q->val)
            return false;
        return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isSameTree(s,t))
            return true;
        if(s!=nullptr)
            return isSubtree(s->right,t) || isSubtree(s->left,t);
        return false;
        
    }
};