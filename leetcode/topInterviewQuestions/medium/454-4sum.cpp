/*https://leetcode.com/problems/4sum-ii/
git@Pedro-Mendes*

/*BruteForce O(n^4) time and O(n) space complexities (NOT ACCEPTED DUE TIME)*/
class Solution {
private:
    void bf(vector< vector<int> > &arrays, int n, int sum, int charIndex, int &solutions) {
        if (sum == 0 && charIndex == -1) 
            solutions++;
        for (int i = 0; i < n && charIndex >= 0; i++)
            bf(arrays,n,sum+arrays[charIndex][i],charIndex-1,solutions);
    }
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector< vector<int> > arrays = {A,B,C,D};
        int solutions = 0;
        bf(arrays, A.size(), 0, 3, solutions);
        return solutions;
    }
};

/*O(n^2) time complexity and O(1) space complexity*/
class Solution {
private:
    unordered_map<int,int> complement;
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int solutions = 0, size = A.size();
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                complement[C[i]+D[j]]++;
            }   
        }
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                solutions += complement[-(A[i]+B[j])];
            }   
        }
        return solutions;
    }
};