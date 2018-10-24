class Solution {
public:
    void combination (int index, const int &n, int k, vector<vector<int>> &solution, const int &target, vector<int> candidates, vector<int> &step, int &sum) {
        if(k==0){
            if(sum == target)
                solution.push_back(step);
            return;
        }
        for(int i = index; i<=n-k;i++){
            step.push_back(candidates[i]);
            sum+=candidates[i];
            combination(i+1,n,k-1,solution,target,candidates,step,sum);
            step.pop_back();
            sum-=candidates[i];
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        vector<int> step;
        vector<vector<int>> solution;
        for (int k=1; k<=n; k++) {
            combination(0,n,k,solution,target,candidates,step,sum);
        }
        return solution;
    }
};