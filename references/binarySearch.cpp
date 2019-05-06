/*
Compare x with the middle element.
If x matches with middle element, we return the mid index.
Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
Else (x is smaller) recur for the left half.
source: https://www.geeksforgeeks.org/binary-search/ 
*/

int binarySearch(vector<int> nums, int l, int r, int x) {
    int mid = l + (r - l)/2;
    if (x == nums[mid]) {
        return mid;
    } else if(x > nums[mid]) {
        return binarySearch(nums,mid+1,r,x);
    } else {
        return binarySearch(nums,l,mid-1,x);
    }
}

     If the next number is larger than current, it show an increasing curve, then the peak must in the right half, else in the left half. 