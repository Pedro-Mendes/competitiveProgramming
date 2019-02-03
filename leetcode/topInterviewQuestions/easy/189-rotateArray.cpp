/* https://leetcode.com/problems/rotate-array/
git@Pedro-Mendes */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> temp(size);
        for (int i = 0; i < nums.size(); i++) {
            temp[i] = nums[((i+size-k%size)%size)];
        }
        nums = temp;
    }
};

/* First optimized solution*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> copy = nums;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[(i+k)%(n)] = copy[i];
        }
    }
};

/* Proposed optimized solution*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), count=0, current, next, prev, tmp;
        k = k % n;                               
        for (int start = 0; count < n; start++) {
            current = start;                           
            prev = nums[current];                       
            do {
                next = (current + k) % n;               
                tmp = nums[next];                            
                nums[next] = prev;                      
                prev = tmp;                             
                current = next;                         
                count++;
            } while(current != start);
        }
    }
};


/*Using reverse*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k==0 || nums.size()==0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);      
        reverse(nums.begin()+k, nums.end());
    }
};