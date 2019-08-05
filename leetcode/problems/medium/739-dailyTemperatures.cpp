/*https://leetcode.com/problems/daily-temperatures/
git@Pedro-Mendes*/

/*O(N) time and space complexity*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size(), top;
        vector<int> output(size,0);
        stack<int> index;
        for (int i = 0; i < size; i++) {
            while (!index.empty() && T[i] > T[index.top()]) {
                top = index.top();
                output[top] = i-top;
                index.pop();
            }
            index.push(i);
        }
        return output;
    }
};