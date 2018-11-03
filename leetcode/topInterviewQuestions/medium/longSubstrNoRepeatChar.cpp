/* https://leetcode.com/problems/longest-substring-without-repeating-characters/
git@Pedro-Mendes */

/*My explanation: https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/188880/C%2B%2B-Simple-Short-solution-using-map-(Explained)*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSize = 0;        
        unordered_map <char, bool> checkedLetter;   
        for (int start = 0, end = 0; start < s.length() && end < s.length();) {
            (!checkedLetter[s[end]]) ? checkedLetter[s[end++]] = true : checkedLetter[s[start++]] = false;
            if(end-start > longestSize)
                longestSize = end-start;
        }
        return longestSize;
    }
};

/*Thanks to claytonjwong for the detailed explanation
https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1817/Easy-to-understand-C%2B%2B-using-sliding-window
*/

class Solution{
public:
    
    int lengthOfLongestSubstring(string s){
        
        int maxlen = 0;
        
        unordered_map<char, bool> dic;
        
        int i=0; // left-side of sliding window
        int j=0; // right-side of sliding window
        
        while (i < s.size() && j < s.size()){
            
            if ( dic.find( s[j] ) == dic.end() ){ // add unique onto right-side of window
                
                //
                // unique char @ j, add char @ j to dic, and move j forward
                // and update maxlen if there is a new max
                //
                dic[ s[j++] ] = true;
                maxlen = max( maxlen, j-i );
                
                
            } else { // drop duplicate from left-side of window
                
                //
                // duplicate char @ j, delete char @ i from dic, and iterate i forward
                //
                dic.erase( s[i++] );
            }
            
        }
        
        return maxlen;
    }
    
};