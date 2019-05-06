/*https://leetcode.com/problems/sort-colors/
git@Pedro-Mendes*/

/*O(n) time complexity and O(1) space complexity*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int firstHalf = 0, middle = 0, secondHalf = nums.size()-1;
        while (middle <= secondHalf) {
            if (nums[middle] == 0) {
                swap(nums[middle++],nums[firstHalf++]);
            } else if (nums[middle] == 1) {
                swap(nums[middle++],nums[firstHalf]);
            } else {
                swap(nums[middle],nums[secondHalf--]);
            }
        }
    }  
};