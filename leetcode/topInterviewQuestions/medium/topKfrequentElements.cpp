/* https://leetcode.com/problems/top-k-frequent-elements/
git@Pedro-Mendes */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int bucketIndexSize;
        int numsSize = nums.size();
        vector< vector<int> > bucket(numsSize+1, vector<int> ());
        vector<int> output;
        for(int i = 0; i < numsSize; i++)
            frequency[nums[i]]++;
        for(unordered_map<int,int>::iterator it = frequency.begin(); it != frequency.end(); it++)
            bucket[it->second].push_back(it->first);
        for(int i = numsSize; i > 0 && k > 0;){
            if(bucket[i].size()>0){
                output.push_back(bucket[i][bucket[i].size()-1]);
                bucket[i].pop_back();
                k--;
            }else{
                i--;
            }
        }
        return output;
    }
};