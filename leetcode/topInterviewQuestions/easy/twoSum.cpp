class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        unordered_map<int, vector<int>> complement;
        for (int i = 0; i < nums.size(); i++) {
            complement[nums[i]].push_back(i);           
        }
        for(int i = 0; i < nums.size(); i++) {
            if (complement[nums[i]].size() > 1 && target-nums[i] == nums[i]) {
                solution.push_back(complement[nums[i]][0]);
                solution.push_back(complement[nums[i]][1]);
                break;
            } else if (complement[target - nums[i]].size()>0 && target-nums[i] != nums[i]) {
                solution.push_back(i);
                solution.push_back(complement[target - nums[i]][0]);
                break;
            }
        }
        return solution;
    }
};