/*https://leetcode.com/problems/container-with-most-water
git@Pedro-Mendes*/

/*O(n) time complexity and O(1) space complexity*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, start = 0, end = height.size()-1, minHeight;
        while(start < end) {
            minHeight = min(height[start],height[end]);
            maxArea = max(maxArea, (end-start)*minHeight);
            if(minHeight == height[start]) {
                start++;
            } else {
                end--;
            }
        }
        return maxArea;
    }
};
