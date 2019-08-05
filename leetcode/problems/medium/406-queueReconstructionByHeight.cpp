/*https://leetcode.com/problems/queue-reconstruction-by-height
git@Pedro-Mendes*/

/*O(N^2) time complexity and O(N) space complexity*/
class Solution {
private:
struct heightAndKComparator{
	bool operator()(vector<int> t1, vector<int> t2) {
        return (t1[0] > t2[0]) || (t1[0] == t2[0] && t1[1] < t2[1]); 
    }
};

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), heightAndKComparator());
        vector<vector<int>> output;
        for(int i = 0; i < people.size(); i++) {
            output.insert(output.begin()+people[i][1], people[i]);
        }
        return output;
    }
};