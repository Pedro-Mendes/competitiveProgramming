/* https://leetcode.com/problems/longest-common-prefix/description/ */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        long long shortestString = strs[0].max_size();
        bool stop = false;
        int shortestIndex=-1, lastIndex=1,stringSize;
        for(int i =0; i< strs.size();i++){
            stringSize = strs[i].size();
            if(stringSize < shortestString){
                shortestString = stringSize;
                shortestIndex = i;
            }
        }
        if(shortestIndex ==-1){
            return "";
        }
        /* cout << "Shortest string on index " << shortestIndex << endl;  */
        for(int i =0; i< strs[shortestIndex].size() && !stop;i++){
            for(int j=0; j<strs.size();j++){
                if(j==shortestIndex)
                    continue;
                if(strs[shortestIndex][i] != strs[j][i]){
                    stop = true;
                    lastIndex = i;
                }
            }
        }
        if(stop == false){
            lastIndex = strs[shortestIndex].size();
        }
        return strs[shortestIndex].substr(0,lastIndex);
    }
};

int main(){
    Solution solve;
    vector<string> input;
    string str;
    while(cin >> str){
        input.push_back(str);
    }
    cout << solve.longestCommonPrefix(input) << endl;
return 0;
}