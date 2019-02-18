/*https://leetcode.com/problems/pascals-triangle/
git@Pedro-Mendes*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> solution;
        for (int i = 0; i < numRows; i++) {
            solution.push_back(vector<int> (i+1,1));
            for (int j = 1; j < i; j++) 
                solution[i][j] = solution[i-1][j-1] + solution[i-1][j];
        }
        return solution;
    }
};