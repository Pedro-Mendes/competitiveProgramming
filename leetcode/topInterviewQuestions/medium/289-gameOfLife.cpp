/*https://leetcode.com/problems/game-of-life/
git@Pedro-Mendes*/

/*O(n*m) time and space complexity*/
class Solution {
private:
    bool inField( int r, int c, int rows, int cols ){
        if( r < 0 || r >= rows ) return false;
        if( c < 0 || c >= cols ) return false;
        return true;
    }
    const int y[8] = { -1, -1, -1,  1, 1, 1, 0, 0 };// 8 shifts to neighbors
    const int x[8] = { -1,  0,  1, -1, 0, 1, -1, 1 };// used in functions 
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors;
        vector<vector<int>> zukunftBoard = board;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                neighbors = 0;
                for(int i = 0; i < 8; i++){// visit the 8 spaces around it
                    if(inField( r+y[i], c+x[i], board.size(), board[r].size())) {
                        if(board[r+y[i]][c+x[i]])
                            neighbors++;
                    }
                }
                if (neighbors < 2 || neighbors > 3) {
                    zukunftBoard[r][c] = 0;
                } else if (neighbors == 3 && !board[r][c]) {
                    zukunftBoard[r][c] = 1;
                }
            }
        }
        board = zukunftBoard;
    }
};

/*O(n*m) time complexity and O(1) space complexity*/
class Solution {
private:
    bool inField( int r, int c, int rows, int cols ){
        if( r < 0 || r >= rows ) return false;
        if( c < 0 || c >= cols ) return false;
        return true;
    }
    const int y[8] = { -1, -1, -1,  1, 1, 1, 0, 0 };// 8 shifts to neighbors
    const int x[8] = { -1,  0,  1, -1, 0, 1, -1, 1 };// used in functions 
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                neighbors = 0;
                for(int i = 0; i < 8; i++){// visit the 8 spaces around it
                    if(inField( r+y[i], c+x[i], board.size(), board[r].size())) {
                        if(board[r+y[i]][c+x[i]] & 1)
                            neighbors++;
                    }
                }
                if (neighbors < 2 || neighbors > 3) {
                    board[r][c] |= 0; //next step second bit will be zero
                } else if (neighbors == 3 && !(board[r][c] & 1)) {
                    board[r][c] |= 2; //2 = 0010 in binary
                } else if ((neighbors == 3 || neighbors == 2) && (board[r][c] & 1)) {
                    board[r][c] |= 2; //2 = 0010 in binary
                }
            }
        }
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                board[r][c] = board[r][c]>>1;
            }
        }
    }
};

