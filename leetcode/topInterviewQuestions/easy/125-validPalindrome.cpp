/*https://leetcode.com/problems/valid-palindrome/
git@Pedro-Mendes*/


/*O(N) time complexity, O(1) space complexity*/
class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.length(), start = 0, end = length-1;
        while(start < end){
            if (tolower(s[start]) > 122 || (tolower(s[start]) < 97 && s[start] > 57) || (s[start] < 48)) {
                start++;
                continue;
            }
            if (tolower(s[end]) > 122 || (tolower(s[end]) < 97 && s[end] > 57) || s[end] < 48) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            start++;
            end--;
            
        }
        return true;
    }
};