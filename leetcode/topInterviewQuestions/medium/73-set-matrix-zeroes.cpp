/*https://leetcode.com/problems/set-matrix-zeroes/
git@pedro-mendes*/

// O(N^2) time and O(1) space complexity.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRowZero = false, firstColumnZero = false;
        for(int c = 0; c < cols; c++) {
            if(matrix[0][c] == 0) {
                firstRowZero = true;
                break;
            }      
        }
        
        for(int r = 0; r < rows; r++) {
            if(matrix[r][0] == 0) {
                firstColumnZero = true;
                break;
            }      
        }
        
        for(int r = 1; r < rows; r++) {
            for(int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        
        for(int c = 1; c < cols; c++) {
            if(matrix[0][c] == 0) {
                for(int r = 0; r < rows; r++) {
                    matrix[r][c] = 0;
                }                
            }      
        }
        
        for(int r = 1; r < rows; r++) {
            if(matrix[r][0] == 0) {
                for(int c = 0; c < cols; c++) {
                    matrix[r][c] = 0;
                }                
            }      
        }
        
        if(firstRowZero) {
            for(int c = 0; c < cols; c++) {
                matrix[0][c] = 0;
            } 
        }
        if(firstColumnZero) {
            for(int r = 0; r < rows; r++) {
                matrix[r][0] = 0;
            } 
        }
    }
};