/*https://leetcode.com/problems/longest-increasing-subsequence
git@Pedro-Mendes*/

/*O(n^2) time complexity and O(n) space complexity*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        vector<int> LIS(nums.size(),1);
        int start = 0, end = 1, maxLength = 1;
        while(start <= end && start != nums.size()-1) {
            if (start == end) {
                start = 0;
                end++;
            } else if(nums[start] < nums[end]) {
                LIS[end] = max(LIS[start]+1,LIS[end]);
                maxLength = max(maxLength,LIS[end]);
                start++;
            } else {
                start++;
            }
        }
        return maxLength;
    }
};

/*Optimized solution TBD*/