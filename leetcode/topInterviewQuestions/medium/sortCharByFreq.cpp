/* https://leetcode.com/problems/sort-characters-by-frequency/
git@Pedro-Mendes */

class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> mappedChars;
        vector<string> bucket(s.length()+1,"");
        string solution="";
        for (int i = 0; i<s.length(); i++)
            mappedChars[s[i]]++;
        for(unordered_map<char, int>::iterator it = mappedChars.begin(); it != mappedChars.end(); it++){
            bucket[it->second].append(it->second,it->first);
        }
        for(int i = bucket.size()-1; i>=0; i--){
            if(bucket[i]!="")
                solution.append(bucket[i]);
        }
        return solution;
    }
};