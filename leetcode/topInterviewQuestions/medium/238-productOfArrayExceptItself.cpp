/*https://leetcode.com/problems/product-of-array-except-self/
git@Pedro-Mendes*/

/*O(N) time and space complexity*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct,rightProduct,solution;
        int mult = 1;
        for (int i = 0; i < nums.size(); i++) {
            leftProduct.push_back(mult);
            mult *= nums[i];
        }
        mult = 1;
        for (int i = nums.size()-1; i > -1; i--) {
            rightProduct.push_back(mult);
            mult *= nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            solution.push_back(leftProduct[i] * rightProduct[nums.size()-i-1]);   
        }
        return solution;
    }
};

/*O(N) time and O(1) space complexity (disregarding output vector)*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int leftProd = 1, rightProd = 1, size = nums.size();
        vector<int> solution(size,1);
        for (int i = 0; i < size; i++) {
            solution[i] *= leftProd;
            leftProd *= nums[i];
            solution[size-i-1] *= rightProd;
            rightProd *= nums[size-i-1];
        }
        return solution;
    }
};