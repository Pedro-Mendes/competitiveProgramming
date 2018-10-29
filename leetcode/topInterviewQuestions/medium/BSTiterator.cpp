
/* https://leetcode.com/problems/binary-search-tree-iterator/description/
git@Pedro-Mendes */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        stackBuilder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!queue.empty())
            return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        int smallest = queue.top();
        queue.pop();
        return smallest;
    }
    
private:
    stack<int> queue;
    
    void stackBuilder(TreeNode* root){
        if(root==nullptr)
            return;
        stackBuilder(root->right);
        queue.push(root->val);
        stackBuilder(root->left);
    }
};
