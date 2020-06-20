/*https://leetcode.com/problems/rotate-image
git@Pedro-Mendes*/

/*O(n^2) time complexity and O(1) space complexity*/
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

// Swaping per element (Gayle Laakman suggestion)
// Same time complexity
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top, offset;
        for(int layer = 0; layer <= matrix.size()/2; layer++) {
            int start = layer;
            int end = matrix.size() - layer - 1;
            for(int i = start; i < end; i++) {
                offset =  i - start;
                top = matrix[start][start + offset];
                matrix[start][start + offset] = matrix[end - offset][start]; //left -> top
                matrix[end - offset][start] = matrix[end][end - offset]; //bottom -> left
                matrix[end][end - offset] = matrix[start + offset][end]; //right -> bottom
                matrix[start + offset][end] = top; //top -> right
            }
        }
    }
};