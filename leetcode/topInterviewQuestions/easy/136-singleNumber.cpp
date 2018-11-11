/* https://leetcode.com/problems/single-number/
git@Pedro-Mendes */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); nums[0] ^= nums[i], i++);
        return nums[0];
    }
};