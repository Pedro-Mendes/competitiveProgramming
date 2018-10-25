/* https://leetcode.com/problems/combination-sum/
git@Pedro-Mendes */

class Solution {
public:
    void combination (int index, const int &n, vector<vector<int>> &solution, const int &target, vector<int> candidates, vector<int> &step, int &sum) {
        if (sum==target){
            solution.push_back(step);
            return;
        }
        if(sum>target)
            return;
        for(int i = index; i<n;i++){
            step.push_back(candidates[i]);
            sum+=candidates[i];
            combination(i,n,solution,target,candidates,step,sum);
            step.pop_back();
            sum-=candidates[i];
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        vector<int> step;
        vector<vector<int>> solution;
        combination(0,n,solution,target,candidates,step,sum);
        return solution;
    }
};

/*Optimization*/
class Solution {
public:
    void combination (vector<vector<int>> &solution, const vector<int> &candidates, int target, int index, vector<int> &step, const int &n) {
        if(target==0){
            solution.push_back(step);
            return;
        }
        if(target<0)
            return;
        for(int i=index;i<n;i++){
            int c = candidates[i];
            if(c<=target){
                step.push_back(c);
                combination(solution, candidates, target-c,i,step,n);
                step.pop_back();
            }
        }
            
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solution;
        vector<int> step;
        int n = candidates.size();
        combination(solution, candidates,target,0,step,n);
        return solution;
    }
};