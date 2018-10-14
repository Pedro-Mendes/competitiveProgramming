/* https://leetcode.com/problems/implement-strstr/ 
git@Pedro-Mendes*/


/*Complexity: O(N*M)*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int j=0,firstIndex=-1,i=0;
        bool found = false;
        if (needle.empty()) {
            return 0;
        } 
        while (i<haystack.length()) {
            if (haystack[i] == needle[j]){
                if (j==0)
                    firstIndex = i;
                if (j==needle.length()-1) {
                    found = true;
                    break;
                }
                j++;
                i++;
            } else if(j!=0 && haystack[i] != needle[j]){
                j=0;
                i = firstIndex+1;
            }else{
                i++;
            }
        }
        if (found)
            return firstIndex;
        return -1;
    }
};