/* https://leetcode.com/problems/missing-number/
git@Pedro-Mendes */

/* Using the sum formula for 1 to N: n(n+1)/2 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            sum+=nums[i];
        }
        return ((n*(n+1))/2) - sum; 
    }
};

/* Using bitwise operations thanks to codingKing https://leetcode.com/problems/missing-number/discuss/69777/C%2B%2B-solution-using-bit-manipulation */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int solution = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            solution ^= nums[i];
            solution ^= i;
        }
        return solution;
    }
};

/* Using the vector itself */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 1)
            return 1-nums[0];
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i && nums[i] < nums.size()) {
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i)
                return i;
        }
        return nums.size();
    }
};