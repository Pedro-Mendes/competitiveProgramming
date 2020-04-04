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

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size(), next = size, start = size,  last = size;
        bool found = false;
        for(int i = 0; i < size; i++) {
            if(nums[i] == 0) {
                next = i;
                start = i+1;
                break;
            }    
        }
        last = next+1;
        while(last < size) {
            for(int i = start; i < size; i++) {
                if(nums[i] != 0) {
                    last = i;
                    found = true;
                    break;
                }
            }
            if(found) {
                nums[next] = nums[last];
                nums[last] = 0;
                next++;
                last++;
                start = last;
            } else {
                break;
            }
        }
    }
};
    