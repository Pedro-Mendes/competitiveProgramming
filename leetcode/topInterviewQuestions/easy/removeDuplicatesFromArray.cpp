/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/ 
git@Pedro-Mendes*/

/*My solution O(N*M)*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastIndex = 0,solution=0;
        bool allNumbersCrawled = false;
        for(int i=0; i<nums.size() && !allNumbersCrawled;i++){
            for(int j=lastIndex; j<nums.size();j++){
                if(nums[i] < nums[j] && i+1<nums.size()){
                    nums[i+1] = nums[j];
                    lastIndex = j;
                    break;
                }
                if(j == nums.size()-1){
                    allNumbersCrawled = true;
                    solution = i+1;
                }
            }
        }
        return solution;
    }
};

/*  Optimized solution from leetcode O(N)*/
public int removeDuplicates(int[] nums) {
    if (nums.length == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.length; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}