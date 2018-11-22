/* https://leetcode.com/problems/first-unique-character-in-a-string/
git@Pedro-Mendes */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> present;
        for (int i = 0; i < s.length(); i++) {
            present[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if(present[s[i]] == 1)
                return i;
        }
        return -1;
    }
};