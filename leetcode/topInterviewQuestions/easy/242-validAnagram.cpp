/* https://leetcode.com/problems/valid-anagram/
git@Pedro-Mendes */

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return (s != t) ? false : true;
    }
};

/* Optimized */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char,int> frequency;
        for (int i = 0; i < s.length(); i++) {
            frequency[s[i]]++;
            frequency[t[i]]--;
        }
        for (int i = 0; i < s.length(); i++) {
           if(frequency[s[i]])
               return false;
        }
        return true;
    }
};