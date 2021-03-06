/* https://leetcode.com/problems/generate-parentheses/
git@Pedro-Mendes */

/*Very dumb solution (not accepted due time complexity)*/
class Solution {
public:
    bool isValidParentheses(string input) {
        int i = input.size()-1;
        stack<char> queue;
        bool error = false;
        if (input[i] == '(')
            return false;
        for (int j=0; j<input.size() && !error;j++) {
            if (input[j]=='(') {
                queue.push(input[j]);
            } else {
                if (!queue.empty()) {
                    queue.pop();
                } else {
                    error = true;
                }
            }
        }
        if(error)
            return false;
        return true;
    }
    void permutation (vector<string> &solution, int index, const int n, string &input, map<string,int> &mapp) {
        if (index == n-1) {
            if (isValidParentheses(input) && !mapp[input]){
                mapp[input] = 1;
                solution.push_back(input);
            }
            return;
        }
        for (int i = index; i<n;i++) {
            if(i!=index && input[i]==input[index])
                continue;
            swap(input[i],input[index]);
            permutation(solution, index+1, n, input,mapp);
        }   
    }
    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        string input="";
        for(int i=0; i<n;i++)
            input+="()";
        map <string,int> mapp;
        permutation(solution,0,2*n,input,mapp);
        return solution;
    }
};

/*Optimization*/

class Solution {
public:
    void backtracking(vector<string> &solution, string step, int open, int close, int max){
        if(step.length()==max*2){
            solution.push_back(step);
            return;
        }
        if(open<max)
            backtracking(solution,step+"(",open+1,close,max);
        if(close<open)
            backtracking(solution,step+")",open,close+1,max);
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        string step="";
        backtracking(solution,step,0,0,n);
        return solution;
    }
};