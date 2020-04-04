class Solution {
private:
    bool isHappyCount(int n, unordered_map<int, bool> &loop) {
        int tmp, sum = 0, digit;
        while(n) {
            tmp = n/10;
            digit = n%10;
            sum += (digit * digit);
            n = tmp;
        }
        if(loop[sum])
            return false;
        if(sum == 1)
            return true;
        loop[sum] = true;
        return isHappyCount(sum,loop);
    }
public:
    bool isHappy(int n) {
        unordered_map<int, bool> loop;
        return isHappyCount(n,loop);
    }
};