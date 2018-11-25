/* https://leetcode.com/problems/rotate-array/
git@Pedro-Mendes */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> temp(size);
        for (int i = 0; i < nums.size(); i++) {
            temp[i] = nums[((i+size-k%size)%size)];
        }
        nums = temp;
    }
};