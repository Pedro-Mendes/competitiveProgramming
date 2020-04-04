class Solution {
private:
    void DFS(stack<int> &s, vector<bool> &checked, vector<vector<int>> &adjMatrix, int current) {
        for (int i = 0; i < adjMatrix[current].size(); i++) {
            if(checked[adjMatrix[current][i]] == true) continue;
            checked[adjMatrix[current][i]] = true;
            DFS(s, checked, adjMatrix, adjMatrix[current][i]);
            }
        s.push(current);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> solution;
        if (!prerequisites.size() || numCourses == 0) {
            for (int i = 0; i < numCourses; i++) {
                solution.push_back(i);
            }
            return solution;
        }
        stack<int> s;
        vector<bool> checked(numCourses, false);
        vector<vector<int>> adjMatrix(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            adjMatrix[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if(adjMatrix[i].size()) {
                if(checked[i] == true) continue;
                checked[i] = true;
                DFS(s,checked, adjMatrix, i);
            }
        }
        if(s.size() == numCourses) {    
            while(!s.empty()) {
                solution.push_back(s.top());
                s.pop();
            }
        }
        return solution;
    }
};