/* https://leetcode.com/problems/move-zeroes/submissions/
git@Pedro-Mendes */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countZeros=0;
        int lastIndex=0;
        for(int i=0 ; i<nums.size();i++){
            if(nums[i] == 0){
                countZeros++;
            }
        }
        for(int i=0 ; i<nums.size();i++){
            if(nums[i]==0){
                if(lastIndex > i)
                    lastIndex=i;
            }else{
                nums[lastIndex] = nums[i];
                lastIndex++;
            }
        }
        for(int i=lastIndex; i<countZeros+lastIndex;i++){
            nums[i]=0;
        }
    }
};