/*https://leetcode.com/problems/powx-n
git@Pedro-Mendes*/

/*source: https://en.wikipedia.org/wiki/Exponentiation_by_squaring*/
class Solution {
private:
    double solve(double x, long long n) {
        if (!n)
            return 1;
        if (n == 1)
            return x;
        if (n%2) //if odd
            return x * solve(x*x,(n-1)/2);
        return solve(x*x, n/2);
}
public:
    double myPow(double x, int n) {
        long long n_long = n;
        if (n < 0) {
            x = 1/x;
            n_long = abs(n_long);
        }
        return solve(x,n_long);
    }
};

/*https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        double t = myPow(x,n/2);
        if (n%2) {
            return n<0 ? 1/x*t*t : x*t*t;
        } else {
            return t*t;
        }
    }
};