/* https://leetcode.com/problems/subsets-ii/description/
git@Pedro-Mendes */

class Solution {
public:
    void combination (const vector<int> &nums, vector< vector<int> > &solution, vector<int> &step, int index, int k, int n) {
        if(k==0){
            solution.push_back(step);
            return;
        }
        
        for(int i=index; i<=n-k; i++){
            if(i>index && nums[i]==nums[i-1])
                continue;
            step.push_back(nums[i]);
            combination(nums,solution,step,i+1,k-1,n);
            step.pop_back();
        }
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector< vector<int> > solution;
        vector<int> step;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int k = 0; k <= n; k++)
            combination(nums,solution,step,0,k,n);
        return solution;
    }
};