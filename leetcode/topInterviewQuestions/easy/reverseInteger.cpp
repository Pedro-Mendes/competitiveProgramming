/* https://leetcode.com/problems/reverse-integer/description/ */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int original) {
        int answ=0;
        int x = original;
        long long test;
        while(x/10 != 0){
            test = (((long long)x%10)+(long long)answ)*10;
            if(test > INT_MAX || test < INT_MIN){
                answ = 0;
                x = 0;
                break;
            }
            answ = ((x%10)+answ)*10;
            x /= 10;
           /*  cout << answ << endl; */
        }
       /*  cout << answ + x << endl; */
        return answ + x;
    }
};

int main(){
    Solution Solve;
    int input;
    cin >> input;
    return Solve.reverse(input);
}