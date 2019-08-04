/*https://leetcode.com/problems/01-matrix/
git@Pedro-Mendes*/

/*O(nm) time and space complexity*/
class Solution {
    int X[4] = {0,0,-1,1};
    int Y[4] = {1,-1,0,0};
    bool withinLimits(vector<vector<int>> &matrix, int i, int j) {
        if (i < matrix.size() && i >= 0) {
            if (j < matrix[i].size() && j >= 0)
                return true;
        }
        return false;
    }
    
    void printMatrix(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return matrix;
        int rows = matrix.size(), cols = matrix[0].size(),x,y;
        queue<pair<int,int>> q;
        pair<int,int> p;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
               matrix[r][c] == 0 ? q.push(make_pair(r,c)) : (void)(matrix[r][c] = INT_MAX);
            }
        }
        while(!q.empty()) {
            p = q.front();
            q.pop();
            x = p.first;
            y = p.second;
            for (int i = 0; i < 4; i++) {
                if(!withinLimits(matrix,x+X[i],y+Y[i]))
                    continue;
                if(matrix[x+X[i]][y+Y[i]] == INT_MAX)
                    q.push(make_pair(x+X[i],y+Y[i]));
                matrix[x+X[i]][y+Y[i]] = min(matrix[x][y]+1, matrix[x+X[i]][y+Y[i]]);                            
            }    
        }
        return matrix;
    }
};