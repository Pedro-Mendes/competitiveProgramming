/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void preorder(TreeNode* root, string &s) {
        if (root) {
            s.push_back(root->val);
            preorder(root->left,s);
            preorder(root->right,s);
        } else {
            s.push_back(0);
        }
    }
    
    void arrayConstructor(string data, TreeNode* current, int n) {
        current->val = data[n];
        if (2*n+1 < data.length()) {
            if(data[2*n+1] != 0) {
                current->left = new TreeNode(0);
                arrayConstructor(data,current->left,2*n+1);    
            }
        }
        if (2*n+2 < data.length()) {
            if(data[2*n+2] != 0) {
                current->right = new TreeNode(0);
                arrayConstructor(data,current->right,2*n+2);    
            }
        }
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serie;
        preorder(root, serie);
        return serie;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        TreeNode* root = new TreeNode(0), *current = root;
        arrayConstructor(data, current, 0);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));