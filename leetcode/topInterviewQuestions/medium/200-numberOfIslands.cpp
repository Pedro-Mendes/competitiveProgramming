/*https://leetcode.com/problems/number-of-islands/
git@pedro-mendes*/

/*O(NxM) time complexity and O(1) space complexity*/
class Solution {
private: 
    void mapIsland(int r, int c, vector<vector<char>>& grid, int height, int width) {      //I'll check only for down and right nighbours
            if (c+1 < width) {
                if (grid[r][c+1] == '1') {
                    grid[r][c+1] = grid[r][c];
                    mapIsland(r,c+1,grid,height,width);
                }
            }
            if (r+1 < height) {
                if(grid[r+1][c] == '1') {
                    grid[r+1][c] = grid[r][c];
                    mapIsland(r+1,c,grid,height,width);
                }
            }
            if (r-1 >= 0) {
                if (grid[r-1][c] == '1') {
                    grid[r-1][c] = grid[r][c];
                    mapIsland(r-1,c,grid,height,width);
                }
            }
            if (c-1 >= 0) {
                if(grid[r][c-1] == '1') {
                    grid[r][c-1] = grid[r][c];
                    mapIsland(r,c-1,grid,height,width);
                }
            }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        int count = 60, height = grid.size(), width = grid[0].size();
        for(int r = 0; r < height; r++) {
            for(int c = 0; c < width; c++) {
                if(grid[r][c] == '1') {
                    grid[r][c] = ++count;
                    mapIsland(r,c,grid,height,width);
                }
            }
        }
        return count-60;
    }
};