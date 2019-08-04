/*https://leetcode.com/problems/counting-bits
git@Pedro-Mendes*/

/*O(n) space and time complexity*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> output(num+1,0);
        for(int i = 1; i <= num; i++) {
            output[i] = output[i&(i-1)] + 1;
        }
        return output;
    }
};