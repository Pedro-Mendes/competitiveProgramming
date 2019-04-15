class Solution {
private:
    /*If the next number is larger than current, it show an increasing curve, then the peak must in the right half, else in the left half. */
    /*O(logn) time and space complexity*/
    int modifiedBinarySearch(vector<int>& nums, int l, int r) {
        if(l == r)
            return r;
        int mid = l + (r - l)/2, //avoidind overflow
        midNext = mid+1;
        if (nums[mid] > nums[midNext]) return modifiedBinarySearch(nums, l, mid);
        if (nums[mid] < nums[midNext]) return modifiedBinarySearch(nums, midNext, r);
        return 0; //the code never reaches this, I left it only so that the compiler does not complain
    }      
public:
    int findPeakElement(vector<int>& nums) {
        return modifiedBinarySearch(nums, 0, nums.size()-1);
    }
};
