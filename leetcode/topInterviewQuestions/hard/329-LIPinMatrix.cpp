class Solution {
private:
    bool isValid(const int &X[],const int &Y[], int r, int c, int m, int n, int i) {
        if (r + X[i] >= m || r + X[i] < 0) return false; 
        if (c + Y[i] >= n || c + Y[i] < 0) return false;
        return true;
    }
    void longestIncreasingPath(const vector<vector<int>>& matrix, map<pair<int,int>,int> &pathSize, int &maxSize,const int &X[],const int &Y[], int r, int c, int m, int n) {
        pair<int, int> step;
        pair<int, int> original = make_pair(r,c);
        if(!pathSize[original])
            pathSize[original] = 1;
        for (int i = 0; i < 4; i++) {
            if(isValid(X,Y,r,c,m,n,i)) {
                if(matrix[r+X[i]][c+Y[i]] > matrix[r][c]) {
                    step = make_pair(r+X[i],c+Y[i]);
                    if(!pathSize[step]) {
                        pathSize[step] = pathSize[original] + 1;
                        longestIncreasingPath(matrix, pathSize, maxSize, step.first, step.second, m, n);
                    } else {
                        pathSize[step] = max(pathSize[step], pathSize[original] + 1);
                    }
                    
                }
                
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
        int X[] = {0,0,1,-1}, Y[] = {-1,1,0,0}, maxSize = 0, m = matrix.size(), n = matrix[0].size;
        map<pair<int,int>,int> pathSize;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                longestIncreasingPath(matrix, pathSize, maxSize, r, c, m, n);
            } 
        }
        return maxSize;
    }
};