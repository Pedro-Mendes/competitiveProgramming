/*https://leetcode.com/problems/happy-number/
git@Pedro-Mendes*/

class Solution {
private:
    bool isHappyCount(int n, unordered_map<int,int> &checked) {
        int tmp = 0;
        while (n) {
            tmp += pow(n%10,2);
            n /= 10;
        }
        if (tmp == 1)
            return true;
        if(checked[tmp])
            return false;
        checked[tmp] = 1;
        return isHappyCount(tmp, checked);
    }
public:
    bool isHappy(int n) {
        unordered_map<int, int> checked;
        return isHappyCount(n, checked);
    }
};