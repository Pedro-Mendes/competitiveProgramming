/*https://leetcode.com/problems/maximum-subarray/
git@Pedro-Mendes*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum+= nums[i];
            maxSum = max(sum,maxSum);
            if (sum < 0)
              sum = 0;
        }
        return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
          return 0;
        int sum = nums[0], first = 0, noFirst = 0, maxLocal = 0, maxGlobal = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            noFirst = sum-nums[first];
            maxLocal = max(max(noFirst, sum), nums[i]);
            if (maxLocal == noFirst) {
                first++;
            } else if(maxLocal == nums[i] && nums[i] != sum) {
                first = i;
            }
            sum = maxLocal;
            maxGlobal = max(maxLocal,maxGlobal);
        }
        return maxGlobal;
    }
};