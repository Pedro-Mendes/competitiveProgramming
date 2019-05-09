/* https://leetcode.com/problems/set-matrix-zeroes/ 
git@Pedro-Mendes*/

/*O(NM) time complexity and O(1) space complexity*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return;
        int cols = matrix[0].size();
        bool firstRowNull = false, firstColumnNull = false;
        for(int i = 0; i < cols; i++) {
            if(matrix[0][i] == 0) {
                firstRowNull = true;
            }
        }
        for(int i = 0; i < rows; i++) {
            if(matrix[i][0] == 0) {
                firstColumnNull = true;
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if(matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if(matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        
        if (firstRowNull) {
            for(int i = 0; i < cols; i++) {
                matrix[0][i] = 0;
            }
        }
        if (firstColumnNull) {
            for(int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};

