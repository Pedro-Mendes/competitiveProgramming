class Solution {
private:
    bool isValid(int X[], int Y[], int r, int c, int m, int n, int i) {
        if (r + X[i] >= m || r + X[i] < 0) return false; 
        if (c + Y[i] >= n || c + Y[i] < 0) return false;
        return true;
    }
    int longestIncreasingPath(const vector<vector<int>>& matrix, vector<vector<int>> &pathSize, int X[], int Y[], int r, int c, int m, int n) {
        if(pathSize[r][c] != 1)
            return pathSize[r][c];
        for (int i = 0; i < 4; i++) {
            if(isValid(X,Y,r,c,m,n,i) && matrix[r+X[i]][c+Y[i]] < matrix[r][c])
                pathSize[r][c] = max(pathSize[r][c], longestIncreasingPath(matrix, pathSize, X, Y, r+X[i], c+Y[i], m, n) + 1);   
        }
        return pathSize[r][c];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
        int X[] = {0,0,1,-1}, Y[] = {-1,1,0,0}, maxSize = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pathSize(m, vector<int> (n,1));
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                pathSize[r][c] = longestIncreasingPath(matrix, pathSize, X, Y, r, c, m, n);
                maxSize = max(maxSize,pathSize[r][c]);
            } 
        }
        return maxSize;
    }
};