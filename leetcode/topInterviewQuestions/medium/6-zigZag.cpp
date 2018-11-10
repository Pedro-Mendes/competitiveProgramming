/* https://leetcode.com/problems/zigzag-conversion/
git@Pedro-Mendes */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        unordered_map <int, string> stringLines;
        string solution;        //PAYPALISHIRING
        int k = 1, step=1;
        for (int i = 0; i < s.length(); i++) {
            if(k==numRows)
                step=-1;
            if(k==1)
                step=1;
            stringLines[k]+=s[i];   //stringLines[1] = PA; stringLines[2]=AP; stringLines[3]=Y;
            k+=step;
        }
        for (int i = 1; i <= numRows; i++) {
            solution+=stringLines[i];
        }
        return solution;
    }
};