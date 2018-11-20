/* https://leetcode.com/problems/plus-one/
git@Pedro-Mendes */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size()-1;
        while(digits[index] == 9 && index >= 0) {   //We are adding 1 to the nines, for instance 1999 turns into 1000 here
            digits[index--] = 0;
        }
        if (index >= 0) {   //No overflow, what I mean is that we are able to add 1 to the current index, therefore 1000 turns into 2000
            digits[index]++;
        } else {
            digits.insert(digits.begin(),1,1);  //Overflow alert, this means, we had something like 9999 and our current index is now -1 and digits is 0000
        }                                       //we insert 1 at the beginning of the vector: 10000
        return digits;
    }
};