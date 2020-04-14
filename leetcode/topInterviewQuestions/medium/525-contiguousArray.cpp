/*https://leetcode.com/problems/contiguous-array/*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> index;
        int count = 0, maxLength = 0;
        index[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            count += (nums[i]? 1:-1);
            if(index.find(count) == index.end())
                index[count] = i;
            else {
                maxLength = max(maxLength, i-index[count]);
            }    
        }
        return maxLength;  
    }
};