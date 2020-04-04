class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); nums[0] ^= nums[i], i++);
        return nums[0];
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answ = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            answ ^= nums[i];
        }
        return answ;
    }
};