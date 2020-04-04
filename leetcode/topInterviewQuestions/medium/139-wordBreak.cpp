/*https://leetcode.com/problems/word-break/
git@Pedro-Mendes*/

/*
Time complexity: O(N^2) general case, worst case O(N^3)
Space complexity: O(N)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length(), longestWord = 0;
        unordered_map<string, bool> dict;
        string word;
        vector<bool> dp(size+1, false);
        dp[0] = true;
        
        for (int i = 0; i < wordDict.size(); i++) {
            dict[wordDict[i]] = true;
            longestWord = max(longestWord, (int)wordDict[i].length());
        }
        
        for(int i = 1; i <= size; i++) {
            for(int j = i-1; j >= max(i-longestWord, 0); j--) {
                if(dp[j]) {
                    word = s.substr(j, i-j);
                    if(dict[word]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[size];
    }
};