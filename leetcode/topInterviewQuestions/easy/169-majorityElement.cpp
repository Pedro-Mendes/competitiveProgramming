/* https://leetcode.com/problems/majority-element/
git@Pedro-Mendes */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int, int> frequency;
        for(int i = 0; i < nums.size(); i++) {
            frequency[nums[i]]++;
            if(frequency[nums[i]] > n)
                return nums[i];
        }
    }
};

/*improved*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};