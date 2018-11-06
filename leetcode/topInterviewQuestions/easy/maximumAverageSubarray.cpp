/* https://leetcode.com/problems/maximum-average-subarray-i/
git@Pedro-Mendes */


/*Time complexity: O(N)  Space complexity: O(1)*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, MAX;
        int i;
        for (i = 0; i < k; i++)
            sum += nums[i];
        MAX = sum;
        for (i = k; i < nums.size(); i++) {
            sum+= -nums[i-k] + nums[i];
            MAX = max(MAX,sum);
        }
        return MAX/k;
    }
};

/*Similar alternativa approach*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                sum+=nums[i];
                MAX = sum;
            } else {
                sum+= -nums[i-k] + nums[i];
                MAX = max(MAX,sum); 
            }
        }
        return MAX/k;
    }