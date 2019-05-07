/*https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
git@Pedro-Mendes*/

/*Time and space complexity O(N)*/
class Codec {
private:
    void serialize(TreeNode* root, ostringstream &serie) {
        if (root) {
            serie << root->val << " ";
            serialize(root->left,serie);
            serialize(root->right,serie);
        } else {
            serie << "N ";
        }
    }
    TreeNode* deserialize(istringstream &serie) {
        string val;
        serie >> val;
        if(val == "N") {
            return nullptr;            
        }    
        TreeNode* current = new TreeNode(stoi(val));
        current->left = deserialize(serie);
        current->right = deserialize(serie);
        return current;
    }
public:
    string serialize(TreeNode* root) {
        ostringstream serie;
        serialize(root, serie);
        return serie.str();
    }
    TreeNode* deserialize(string data) {
        if (data.empty())   
            return nullptr;
        istringstream serie(data);
        return deserialize(serie);
    }
};