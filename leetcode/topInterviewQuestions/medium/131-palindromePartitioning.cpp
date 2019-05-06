/*https://leetcode.com/problems/palindrome-partitioning/
git@Pedro-Mendes*/

/*Time complexity : O(N *2^N), space complexity O(N^2)*/
class Solution {
private:
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    void partition(const string &s, int start, vector<string> &current, vector<vector<string>> &output, int length) {
        if (start == length) {
            output.push_back(current);                              //s = "aab"
        } else {                                                   //length = 3
            for (int i = start; i < length; i++) {                 //start = 2 i=2
                if(isPalindrome(s,start,i)) {                          //current = ["aa",]      output = [["a","a","b"],[]]
                    current.push_back(s.substr(start, i-start+1));
                    partition(s,i+1,current,output,length);
                    current.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {        //s = "aab"
        vector<vector<string>> output;
        vector<string> current;
        partition(s, 0, current, output, s.length());
        return output;
    }
};

/*https://leetcode.com/problems/palindrome-partitioning/discuss/42101/C%2B%2B-backtracking*/