class Solution {
public:
    void combination(int index, int n, int k, vector<int> &step, vector<vector<int>> &solution) {
      if (k == 0) {
        solution.push_back(step);
        return;
      }
      for (int i = index; i <= n-k; i++) {
        step.push_back(i+1);
        combination (i+1,n,k-1,step,solution);
        step.pop_back();
      }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> solution;
        vector<int> step;
        combination(0,n,k,step,solution);
        return solution;
    }
};

/*With bitmask solution*/
class Solution {
public:
    void combination (int n, int k, vector<vector<int>> &solution) {
        string bitmask(k, 1); 
        bitmask.resize(n, 0);
        vector<int> step;
        do{
            for (int i = 0; i < n; i++) {
                if (bitmask[i]) 
                    step.push_back(i+1);
            }
            solution.push_back (step);
            step = vector<int> ();
        }while (prev_permutation(bitmask.begin(), bitmask.end()));
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> solution;
        combination(n,k,solution);
        return solution;
    }
};