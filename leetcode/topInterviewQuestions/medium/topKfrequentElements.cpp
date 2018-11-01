class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        vector< vector<int> > bucket(nums.size());
        vector<int> output;
        for(int i = 0; i < nums.size(); i++)
            frequency[nums[i]]++;
        for(unordered_map<int,int>::iterator it = frequency.begin(); it != frequency.end(); it++)
            bucket[it->second].push_back(it->first);
        for(int i = bucket.size(); i >= 0 && k > 0; i--){
            if(bucket[i].size()){
                output.push_back(bucket[i]);
                k--;
            }
        }
        return output;
    }
};