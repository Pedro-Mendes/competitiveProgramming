/*https://leetcode.com/problems/search-a-2d-matrix-ii
git@Pedro-Mendes*/

/*O(N+M) time complexity and O(1) space complexity*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size())
            return false;
        int height = matrix.size(), width = matrix[0].size(), r = height-1, c = 0;
        while (r >= 0 && c < width) {
            if (matrix[r][c] > target) {
                r--;
            } else if (matrix[r][c] < target) {
                c++;
            } else {
                return true;
            }
        }
        return false;
    }
};

/*https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66207/My-C%2B%2B-soluation-using-Binary-search-Tree-model-beats-100~~~~*/