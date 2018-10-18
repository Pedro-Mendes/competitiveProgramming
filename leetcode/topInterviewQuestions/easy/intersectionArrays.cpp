/* https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/
git@Pedro-Mendes */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map <int,int> m;
        vector<int> answer;
        for(int i=0; i<nums1.size();i++){
            m[nums1[i]] +=1;
        }
        for(int i=0; i<nums2.size();i++){
            if(m[nums2[i]] > 0){
                answer.push_back(nums2[i]);
                m[nums2[i]] = m[nums2[i]]-1;
            }
        }
        return answer;
    }
};