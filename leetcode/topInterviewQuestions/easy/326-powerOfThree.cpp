/*https://leetcode.com/problems/power-of-three/
git@Pedro-Mendes*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 3) {
            if (((double)n/3) != n/3)
                return false;
            n /=3;
        }
        if (n == 3 || n == 1)
            return true;
        return false;
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        double answ = (log10(n) / log10(3));
        return (int)(log10(n) / log10(3) == (log10(n) / log10(3) ? true : false;
    }
};
/*Really good solutions: 
https://leetcode.com/problems/power-of-three/discuss/77876/**-A-summary-of-all-solutions-(new-method-included-at-15%3A30pm-Jan-8th)*/