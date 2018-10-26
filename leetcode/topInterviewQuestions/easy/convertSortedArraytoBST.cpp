/* https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
git@Pedro-Mendes */
class Solution {
public:
    TreeNode* binarySearch(const vector<int> &nums,int l, int r){
        if(l>r)
            return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left = binarySearch(nums, l,mid-1);
        root->right = binarySearch(nums, mid+1, r);
        return root;
    }
  
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        int l = 0;
        int r = nums.size()-1;
        return binarySearch(nums,l,r);
            
    }
};