class Solution {
/* https://leetcode.com/problems/permutations
git@Pedro-Mendes 
thanks to http://faculty.cse.tamu.edu/djimenez/ut/utsa/cs3343/lecture25.html
*/

public:
    void swap(vector<int> &nums,int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void perm(vector<vector<int>> &solution, vector<int> &nums, int index){
        if(index == nums.size()){
            solution.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums,index,i);
            perm(solution,nums,index+1);
            swap(nums,i,index);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;
        perm(solution,nums,0);
        return solution;
    }
};