/* https://leetcode.com/problems/letter-combinations-of-a-phone-number/
git@Pedro-Mendes */

/*
Time and space complexity, assuming in worsat case 4 letters on the phone button
O(4N)
*/
class Solution {
private:
    vector<string> answ;
    vector<string> phone;
    
    void backTracking(string current, string left, int expectedSize) {
        if (left.length() == 0 && current.length() == expectedSize) {
            answ.push_back(current);
            return;
        }
        for(int j = 0; j < left.length(); j++) {
            for(int i = 0; i < phone[left[j]-'2'].length(); i++) {
                backTracking(current+phone[left[j]-'2'][i], left.substr(j+1), expectedSize);  
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return answ;
        phone.reserve(8);
        phone.push_back("abc");
        phone.push_back("def");
        phone.push_back("ghi");
        phone.push_back("jkl");
        phone.push_back("mno");
        phone.push_back("pqrs");
        phone.push_back("tuv");
        phone.push_back("wxyz");
        backTracking("", digits, digits.length());
        return answ;
    }
};