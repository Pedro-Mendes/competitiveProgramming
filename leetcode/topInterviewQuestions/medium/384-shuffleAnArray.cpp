/*https://leetcode.com/problems/shuffle-an-array/
git@Pedro-MEndes*/

/*O(N) time and space complexity*/
class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int> nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> array = original;
        for (int i = 0; i < array.size(); i++) {
            int index = rand() % array.size();
            swap(array[i],array[index]);
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */