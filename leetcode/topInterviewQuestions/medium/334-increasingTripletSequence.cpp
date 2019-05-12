class Solution {
private:
    void binaryCeilSearch(vector<int> &input, vector<int> &solution, int left, int right, int target, int &nextLargerVal) {
    int mid = left + (right-left)/2;
    if (left > right)
        return;
    if (input[solution[mid]] >= target) {
        nextLargerVal = mid;
        return binaryCeilSearch(input, solution, left, mid-1, target, nextLargerVal);
    } else { //input[mid] < target
        return binaryCeilSearch(input, solution, mid+1, right, target, nextLargerVal);
    }
}
public:
    bool increasingTriplet(vector<int>& input) {
        if (input.size() < 3)
            return false;
        vector<int> solution;
        int length = 1, nextLargerVal;
        solution.push_back(0);
        for (int i = 0; i < input.size(); i++) {
            if (input[solution[length-1]] < input[i]) {
                solution.push_back(i);
                length++;
                if (length >= 3)
                    return true;
            } else {
                binaryCeilSearch(input, solution, 0, length-1, input[i], nextLargerVal);
                solution[nextLargerVal] = i;
            }
        }
        return false;
    }
};