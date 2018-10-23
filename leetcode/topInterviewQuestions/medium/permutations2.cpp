class Solution {
public:
    void swap(vector<int> &nums,int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void permute(vector<vector<int>> &solution, vector<int> nums, int index, map<vector<int>,int> &hash){
        if(index==nums.size()){
            if(!hash[nums]){
                solution.push_back(nums);
                hash[nums]=1;
            }
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums,i,index);
            permute(solution,nums,index+1,hash);
            swap(nums,index,i);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<vector<int>,int> hash;
        vector<vector<int>> solution;
        permute(solution,nums,0,hash);
        return solution;
    }
};

/*Optimized solution thanks to guoang
https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines*/

class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

/*My improved solution with the above implemented*/

class Solution {
public:
    void permute(vector<vector<int>> &solution, vector<int> nums, int index, int size){
        if(index==size-1){
            solution.push_back(nums);
            return;
        }
        for(int i=index;i<size;i++){
            if(i!=index && nums[i]==nums[index])
                continue;
            swap(nums[i],nums[index]);
            permute(solution,nums,index+1,size);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> solution;
        permute(solution,nums,0,size);
        return solution;
    }
};

