/*https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters
git@pedro-mendes*/

/*O(n^2) time and O(n) space complexity*/
class Solution {
private:
    int longestSubstring(string s, int k, int left, int right) {
        if(left < 0 || left > right || k > right-left+1)
            return 0;
        int count[26] = {0}, firstHalf, secondHalf;
        for (int i = left; i <= right; i++) {
            count[s[i]-'a']++;
        }
        for(int i = left; i <= right; i++) {
            if(count[s[i]-'a'] < k) {
                firstHalf = longestSubstring(s,k,left,i-1);
                secondHalf = longestSubstring(s,k,i+1,right);
                return max(firstHalf, secondHalf);
            }
        }
        return right-left+1;     
    }
public:
    int longestSubstring(string s, int k) {
        if(s.length() == 0)
            return 0;
        if (k == 0)
            return s.length();
        return longestSubstring(s,k,0,s.length()-1);
    }
};






/*Optimized*/
class Solution {
private:
int longestSubstring_recur(const string& s, int k, int first, int last) {
    int count[26] = {0};
    for (int j = first; j < last; ++j) ++count[s[j] - 'a'];
    
    int max_len = 0;
    for (int j = first; j < last;) {
        while (j < last && count[s[j]-'a']<k) ++j;
        if (j == last) break;
        int l = j;
        while (l < last && count[s[l]-'a']>=k) ++l;
        //all chars appear more than k times
        if (j == first && l == last) return last-first; 
        max_len = max(max_len, longestSubstring_recur(s, k, j, l));
        j = l;
    }
    return max_len;
}
public:
int longestSubstring(string s, int k) {
    return longestSubstring_recur(s, k, 0, s.size());
}
};