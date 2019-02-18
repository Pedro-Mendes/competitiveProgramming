/*https://leetcode.com/problems/reverse-bits
git@Pedro-Mendes*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t solution = 0, 
            tmp, 
            count = 31;
        while (n > 0) {
            tmp = n & 1;
            tmp = tmp << count; 
            solution = solution | tmp;
            n = n >> 1;
            count--;
        }
        return solution;
    }
};