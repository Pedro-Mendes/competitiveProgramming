/*https://leetcode.com/problems/subsets/
git@Pedro-Mendes*/

class Solution {
public:
    void combination(int index, int k, vector<int> nums, int n, vector<vector<int>> &solution, vector<int> &step){
        if(k==0){
            solution.push_back(step);
            return;
        }
        for(int i = index; i<=n-k;i++){
            step.push_back(nums[i]);
            combination(i+1,k-1,nums,n,solution,step);
            step.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        int n = nums.size();
        int index = 0;
        vector<int> step;
        solution.push_back(step);
        /*O(k*n^k) complexity*/
        for(int k=1; k<=n;k++){
            combination(index,k,nums,n,solution,step);
        }
        return solution;
    }
};