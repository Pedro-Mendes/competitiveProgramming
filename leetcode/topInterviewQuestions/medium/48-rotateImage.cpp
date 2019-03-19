/*https://leetcode.com/problems/rotate-image
git@Pedro-Mendes*/

/*O(n) time complexity and O(1) space complexity*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //invert rows
        int n = matrix.size();
        for (int i = 0; i < n/2; i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
        //swap symetric ones
        for (int i = 0; i < n; i++) {
            for(int j = i; j < matrix[i].size(); j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};