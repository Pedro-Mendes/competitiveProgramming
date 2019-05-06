/*https://leetcode.com/problems/kth-largest-element-in-an-array/
git@Pedro-Mendes*/

/*O(nLogn) time and O(1) space complexity*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};