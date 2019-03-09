/*https://leetcode.com/problems/factorial-trailing-zeroes
git@Pedro-Mendes*/


/*O(log5(n)) time and O(1) space solutions*/
class Solution {
public:
    int trailingZeroes(int n) {
        int c = 0;
        while (n >= 5) {
            n /= 5;
            c += n;
        }
        return c;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0? 0 : n/5 + trailingZeroes(n/5);
    }
};