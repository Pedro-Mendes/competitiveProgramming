/*https://leetcode.com/problems/longest-increasing-subsequence
git@Pedro-Mendes*/

/*O(n^2) time complexity and O(n) space complexity*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        vector<int> LIS(nums.size(),1);
        int start = 0, end = 1, maxLength = 1;
        while(start <= end && start != nums.size()-1) {
            if (start == end) {
                start = 0;
                end++;
            } else if(nums[start] < nums[end]) {
                LIS[end] = max(LIS[start]+1,LIS[end]);
                maxLength = max(maxLength,LIS[end]);
                start++;
            } else {
                start++;
            }
        }
        return maxLength;
    }
};

/*Optimized time solution:
O(nLogn) time complexity and O(n) space complexity
*/
class Solution {
private:
    int binarySearchCeil(const vector<int> &solution, int l, int r, int target, int &nextVal, const vector<int> &input) {
        if (l > r)
            return nextVal;
        int mid = l + (r-l)/2;
        if (input[solution[mid]] >= target){
            nextVal = mid;
            return binarySearchCeil(solution, l, mid-1, target, nextVal, input);
        } else { //solution[mid] < target
            return binarySearchCeil(solution, mid+1, r, target, nextVal, input);
        }
    }
public:
    int lengthOfLIS(vector<int>& input) {
        vector<int> solution;
        int size = input.size(),length = 1, indexNextLargerNum,nextVal;
        if (size == 0)
            return 0;
        solution.push_back(0);
        for(int i = 1; i < size; i++) {
            if (input[solution[length-1]] < input[i]) {
                solution.push_back(i);
                length++;
            } else {
                indexNextLargerNum = binarySearchCeil(solution,0,length-1,input[i],nextVal, input);
                solution[indexNextLargerNum] = i;
            }
        }
        return length;
    }
};