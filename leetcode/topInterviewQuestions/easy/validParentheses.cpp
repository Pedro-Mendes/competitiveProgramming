/* https://leetcode.com/problems/valid-parentheses/ 
git@Pedro-Mendes*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string input) {
        bool errorFound = false;
        stack<string> s;
        if(!input.size()){
            return "true";
        }
        for(int i=0 ;i<input.size() && !errorFound;i++){
            switch(input[i]){
                case'(':
                    s.push("parentheses");
                    break;
                case')':
                    if(s.empty()){
                        errorFound = true;
                    }else if(s.top()!="parentheses"){
                        errorFound = true;
                    }else{
                        s.pop();
                    }
                    break;
                case'{':
                    s.push("braces");
                    break;
                case'}':
                    if(s.empty()){
                        errorFound = true;
                    }else if(s.top()!="braces"){
                        errorFound = true;
                    }else{
                        s.pop();
                    }
                    break;
                case'[':
                    s.push("brackets");
                    break;
                case']':
                    if(s.empty()){
                        errorFound = true;
                    }else if(s.top()!="brackets"){
                        errorFound = true;
                    }else{
                        s.pop();
                    }
                    break;
            }
        }
        if(errorFound || !s.empty()){
            //cout << "false" << endl;
            return false;
        }
        //cout << "true" << endl;
        return true;
    }
};

int main(){
    string s;
    cin >> s;
    Solution solve;
    solve.isValid(s);
    return 0;
}