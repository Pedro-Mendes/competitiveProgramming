/*https://leetcode.com/problems/house-robber/
git@Pedro-Mendes*/

/*DP O(N) time and space complexity*/
class Solution {
private:
    int solve(vector<int>& nums, int index, unordered_map <int,int> &map) {
        if (index >= nums.size())
            return 0;
        if (map.find(index) == map.end())
            map[index] = max(nums[index]+solve(nums,index+2,map),solve(nums,index+1,map));
        return map[index];
    }
    
public:
    int rob(vector<int>& nums) {
        unordered_map <int,int> map;
        return solve(nums, 0,map);
    }
};


/*Improved solution, O(N) time and O(1) space complexity*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int including = 0, excluding = 0, includePrevious;
        for (int i = 0; i < nums.size(); i++) {
            includePrevious = including;
            including = nums[i] + excluding;
            excluding = max(excluding, includePrevious);
        }
        return max(including, excluding);
    }
};