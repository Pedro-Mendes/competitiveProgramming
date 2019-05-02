/*https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
git@Pedro-Mendes*/

/*O(N) space complexity and O(N^2) time complexity*/
class Solution {
private:
    TreeNode* createNode(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inStart, int inEnd, const int preSize) {
        if (preIndex >= preSize || inStart > inEnd)
            return nullptr;
        int inIndex;
        TreeNode* root = new TreeNode(preorder[preIndex]);
        for(int i = inStart; i <= inEnd; i++) {
            if (preorder[preIndex] == inorder[i]) {
                inIndex = i;
                break;
            }
        }
        preIndex++;
        root->left = createNode(preorder, inorder, preIndex, inStart, inIndex-1, preSize);
        root->right = createNode(preorder, inorder, preIndex, inIndex+1, inEnd, preSize);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0, preSize = preorder.size();
        return createNode(preorder, inorder, preIndex, 0, inorder.size(), preSize);
    }
};

/*Iterative solution*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0, size = preorder.size(), inIndex = 0;
        stack<TreeNode*> st;
        if(preorder.empty())
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        TreeNode* current = root;
        st.push(current);                                                              
        while (!st.empty()) {                                   
            while(st.top()->val != inorder[inIndex]) {
                st.top()->left = new TreeNode(preorder[preIndex++]);            
                st.push(st.top()->left);
            }
            while(!st.empty() && st.top()->val == inorder[inIndex]) {                   
                current = st.top();
                st.pop();
                ++inIndex;
            }
            if (preIndex < size) {
                current->right = new TreeNode(preorder[preIndex++]);
                current = current->right;
                st.push(current);
            }
        }
        return root;
    }
};
/*
preorder: 
root, left, right
inorder:
left, root, right
postorder:
left, right, root
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34562/Sharing-my-straightforward-recursive-solution
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34555/The-iterative-solution-is-easier-than-you-think!
*/