/*https://leetcode.com/problems/palindromic-substrings/
git@Pedro-Mendes*/

/*O(N^2) time complexity and O(1) space complexity*/
class Solution {
private:
    void isPalindrome(string s, int start, int end, int &count) {
        while(start >= 0 && end < s.length() && s[start] == s[end]){ 
            count++;
            start--;
            end++;
        }
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            isPalindrome(s, i, i, count);
            isPalindrome(s, i, i+1, count);
        }
        return count;
    }
};