/* https://leetcode.com/problems/contains-duplicate/
git@Pedro-Mendes */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (int i = 0; i < nums.size(); i++) {
            if (++frequency[nums[i]] > 1) 
                return true;
        }
        return false;
    }
};

/* Not as good as the above one, but really nice
Thanks to namanrajpal16: https://leetcode.com/problems/contains-duplicate/discuss/165182/C%2B%2B-One-Liner! */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return (std::unordered_set<int>{nums.begin(),nums.end()}.size()!=nums.size());
    }
};