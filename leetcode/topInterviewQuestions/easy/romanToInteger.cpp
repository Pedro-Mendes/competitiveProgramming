/* https://leetcode.com/problems/roman-to-integer/description/ 
git@Pedro-Mendes*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            int size = s.size();
            int answer = 0,i=0;
            while(i < size){
                switch(s[i]){
                    case 'I':
                        if(i+1<size){
                            if(s[i+1] == 'V'){
                                answer+= 4;
                                i+=1;
                            }else if(s[i+1] == 'X'){
                                answer+= 9;
                                i+=1;
                            }else{
                                answer+=1;
                            }
                        }else{
                            answer+=1;
                        }
                        break;
                    case 'V':
                        answer+=5;
                        break;
                    case 'X':
                        if(i+1<size){
                            if(s[i+1] == 'L'){
                                answer+= 40;
                                i+=1;
                            }else if(s[i+1] == 'C'){
                                answer+= 90;
                                i+=1;
                            }else{
                                answer+=10;
                            }
                        }else{
                            answer+=10;
                        }
                        break;
                    case 'L':
                        answer+=50;
                        break;
                    case 'C':
                        if(i+1<size){
                            if(s[i+1] == 'D'){
                                answer+= 400;
                                i+=1;
                            }else if(s[i+1] == 'M'){
                                answer+= 900;
                                i+=1;
                            }else{
                                answer+=100;
                            }
                        }else{
                            answer+=100;
                        }
                        break;
                    case 'D':
                        answer+=500;
                        break;
                    case 'M':
                        answer+=1000;
                        break;
                }
                ++i;                
            }
            return answer;
        }
    };

int main(){
    string roman;
    cin >> roman;    
    Solution solve;
    cout << solve.romanToInt(roman) << endl;
    return 0;
}