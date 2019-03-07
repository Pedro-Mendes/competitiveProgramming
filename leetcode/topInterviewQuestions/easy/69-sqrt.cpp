/*https://leetcode.com/problems/sqrtx
git@Pedro-Mendes*/

class Solution {
private:
    int binarySearch(int &x, double min, double max) {
        double mid = (max + min)/2;
        double midSquared = mid*mid;
        if (floor(midSquared) == x){
            return (int)mid;
        } else if (floor(midSquared) > x) {
            return binarySearch(x, min, mid-1);
        } else {
            return binarySearch(x, mid+1, max);
        }
        
    }

public:
    int mySqrt(int x) {
        return binarySearch(x,0,x);
    }
};