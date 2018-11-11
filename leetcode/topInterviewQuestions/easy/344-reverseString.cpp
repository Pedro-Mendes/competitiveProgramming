/* https://leetcode.com/problems/reverse-string/
git@Pedro-Mendes */

class Solution {
public:
    string reverseString(string s) {            //drbckailb length = 9 
        int length = s.length();
        for(int i = 0; i < length/2; i++)       // < 4
            swap(s[i],s[length-1-i]);
        return s;
    }
};