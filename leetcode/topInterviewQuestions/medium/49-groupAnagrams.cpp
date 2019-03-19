/*https://leetcode.com/problems/group-anagrams/
git@Pedro-Mendes*/

/*O(n*kLogk)time complexity and O(n) space complexity*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector< vector<string>> output;
        unordered_map<string, int> check;
        string tmp;
        int c = 1;
        for (int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            if (check[strs[i]]) {
                output[check[strs[i]]-1].push_back(tmp);
            } else {
                output.push_back(vector<string> ());
                check[strs[i]] = c++;
                output[check[strs[i]]-1].push_back(tmp);
            }    
        }
        return output;
    }
};
    
    
