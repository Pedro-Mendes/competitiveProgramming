class Solution {
private: 
    /*x and y are useful array to check all neihbors and the element itself in a grid*/
    int x[9] = {-1,-1,-1,0,0,0,1,1,1};
    int y[9] = {-1,0,1,-1,0,1,-1,0,1};

    /*Since it is valid to assume that the whole grid will be 9x9 we already know the subgrid centers:
    (1,1), (1,4), (1,7)
    (4,1), (4,4), (4,7)
    (7,1), (7,4), (7,7)
    */
    int subGrid[3] = {1,4,7};

    /*The maps are used to 'map' (right?) the row, column and subgrid values, respectively*/
    unordered_map<char,int> rCheck;
    unordered_map<char,int> cCheck;
    unordered_map<char,int> gridCheck;
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        /*Checking row by row and mapping the elements to avoid repetition*/
        for(int r = 0; r < 9; r++) {
            rCheck = unordered_map<char,int> ();
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.')
                    continue;
                if(rCheck[board[r][c]] == r+1)
                    return false;
                rCheck[board[r][c]] = r+1;
            }
        }
        
        /*Checking column by column and mapping the elements to avoid repetition*/        
        for(int c = 0; c < 9; c++) {
            cCheck = unordered_map<char,int> ();
            for (int r = 0; r < 9; r++) {
                if (board[r][c] == '.')
                    continue;
                if(cCheck[board[r][c]] == c+1)
                    return false;
                cCheck[board[r][c]] = c+1;
            }
        }
        
        /*Checking each subgrid*/

        /*
        Subgrid[r] and subgrid[c] will give us the coordenates for the subgrid centers.
        */
        for(int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                gridCheck = unordered_map<char,int> ();
                
                /*Using our auxiliary arrays, we can go through each neighbor and the center itself.*/
                for(int i = 0; i < 9; i++){   
                    if (board[subGrid[r]+x[i]][subGrid[c]+y[i]] == '.')
                        continue;
                    if(gridCheck[board[subGrid[r]+x[i]][subGrid[c]+y[i]]])
                        return false;
                    gridCheck[board[subGrid[r]+x[i]][subGrid[c]+y[i]]]++;
                }
            }
        }
        return true;
    }
};
//check entire row = check vetor by vector
//check entire col  = check same indes of all vectors
//chech each 3x3 sub grid


/* [
["9",   ,       ,"6",   ,   ,      ,   ,   ],
[   ,   ,       ,   ,"6",   ,      ,   ,   ],
[   ,   ,       ,   ,   ,"1",      ,"3",   ],

[   ,   ,       ,   ,   ,   ,      ,   ,"8"],
[   ,   ,       ,   ,   ,"8",      ,   ,   ],
[   ,   ,       ,"4",   ,   ,   "2",   ,   ],

[   ,   ,       ,   ,   ,   ,      ,   ,"1"],
["6",   ,       ,   ,"1",   ,      ,   ,   ],
[   ,   ,       ,   ,   ,   ,      ,   ,   ]
] */