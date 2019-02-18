/*https://leetcode.com/problems/climbing-stairs/
git@Pedro-Mendes
*/

class Solution {
private:
    int solveClimbStairs(int n, unordered_map<int, int> &checked) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        int ways = 0;
        if (checked[n-1]) {
            ways += checked[n-1];
        } else {
            ways += solveClimbStairs(n-1,checked);
            checked[n-1] = ways;
        }
        if (checked[n-2]) {
            ways += checked[n-2];
        } else {
            ways += solveClimbStairs(n-2,checked);
            checked[n-1] = ways;
        }
        return ways;
    }
public:
    int climbStairs(int n) {
        unordered_map<int, int> checked;
        return solveClimbStairs(n, checked);
    }
};