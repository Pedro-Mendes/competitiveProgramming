/*https://leetcode.com/problems/count-of-smaller-numbers-after-self/
git@Pedr-Mendes*/

/*Space complexity O(N), Time complexity O(NLogN)*/
class Solution {
private:
    void countSmaller(const vector<int>& input, vector<int>& output, vector<int>& index, int start, int end) {
        int size = end-start;
        if (size > 1) {
            vector<int> indexTmp;
            int step = size/2, mid = start + step, s = start, e = mid, count = 0;
            countSmaller(input, output, index, start, mid);
            countSmaller(input, output, index, mid, end);
            while (s < mid || e < end) {
                if (e == end || s < mid && input[index[s]] <= input[index[e]]) {       //in order
                    indexTmp.push_back(index[s]);
                    output[index[s++]] += count;
                } else {                                        //out of order
                    indexTmp.push_back(index[e++]);
                    count++;
                }
            }
            move(indexTmp.begin(), indexTmp.end(), index.begin()+start);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> output(size,0), index;
        for(int i = 0; i < size; i++)
            index.push_back(i);
        countSmaller(nums, output, index, 0, size);
        return output;
    }
};

/*https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76607/C%2B%2B-O(nlogn)-Time-O(n)-Space-MergeSort-Solution-with-Detail-Explanation*/