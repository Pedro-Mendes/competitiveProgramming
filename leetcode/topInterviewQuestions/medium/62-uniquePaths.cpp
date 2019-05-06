/*https://leetcode.com/problems/unique-uniquePaths
git@Pedro-Mendes*/

/*Bruteforce O(n*m) time and space complexity (Time limit exceeded)*/ 
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (!m && !n)
            return 0;
        int count = 1;
        for (int i = m+n-2; i > 0; i--) {
            count *= i;
        }
        for (int i = m-1; i > 0; i--) {
            count /= i;
        }
        for (int i = n-1; i > 0; i--) {
            count /= i;
        }
        return count;
    }
};

/*Dynamic programming solution, O(n*m) space complexity*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (!m && !n)
            return 0;
        vector< vector<int> > matrix(m, vector<int>(n,0));
        matrix[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i-1 >= 0)
                    matrix[i][j]+=  matrix[i-1][j];
                if (j-1 >= 0)
                    matrix[i][j]+=  matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};
