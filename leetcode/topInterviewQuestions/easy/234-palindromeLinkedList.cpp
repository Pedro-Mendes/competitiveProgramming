/* https://leetcode.com/problems/palindrome-linked-list
git@Pedro-Mendes */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*O(n) time and space complexity*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        int size;
        while(head != nullptr) {
            values.push_back(head->val);
            head = head -> next;
        }
        size = values.size();
        for (int i = 0; i < size/2; i++) {
            if(values[i] != values[size-1-i])
                return false;
        }
        return true;
    }
};