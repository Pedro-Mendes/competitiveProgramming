/*https://leetcode.com/problems/excel-sheet-column-number/submissions/
Pedro-Mendes*/


/* O(N) time, O(1) space*/
class Solution {
public:
    int titleToNumber(string s) {
        int size = s.length(), answ=0;
        for (int i = 0; i < size; i++) {
            answ += ((s[i]-64)*pow(26,size-i-1));
        }
        return answ;
    }
};