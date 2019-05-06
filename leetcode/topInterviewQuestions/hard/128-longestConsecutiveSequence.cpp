/*ttps://leetcode.com/problems/longest-consecutive-sequence
git@Pedro-Mendes*/

/*O(N) time and space complexity*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int previous, maxSequenceLength = 1, sequence = 1;
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        map<int,int>::iterator it = m.begin();
        previous = it->first;
        it++;
        while (it != m.end()) {
            if (it->first != previous+1) {
                sequence = 1;
            } else {
                sequence++;
                maxSequenceLength = max(maxSequenceLength, sequence);
            }
            previous = it->first;
            it++;
        }
        return maxSequenceLength;
    }
};