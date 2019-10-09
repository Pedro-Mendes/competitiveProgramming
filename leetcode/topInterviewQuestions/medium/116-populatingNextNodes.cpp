/*https://leetcode.com/problems/populating-next-right-pointers-in-each-node
git@Pedro-Mendes*/

//O(N) time and O(Height) space complexity
class Solution {
private:
    void preorder(Node* root, int level, unordered_map<int, Node*> &m) {
        if(!root)
            return;
        if(m[level]) {
            root->next = m[level];
        }
        m[level] = root;
        preorder(root->right, level+1, m);
        preorder(root->left, level+1, m);
    }

public:
    Node* connect(Node* root) {
        unordered_map<int, Node*> m;
        preorder(root,0,m);
        return root;
    }
};