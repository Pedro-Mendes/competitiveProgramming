/*https://leetcode.com/problems/add-two-number
git@Pedro-Mendes*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*O(n) time complexity and O(1) space complexity*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1, *tail = l1, *remain;
        int overflow = 0;
        while(l1 && l2) {
            if (l1->val + l2->val + overflow > 9) {
                l1->val = (l1->val + l2->val + overflow) % 10;
                overflow = 1;
            } else {
                l1->val = l1->val + l2->val + overflow;
                overflow = 0;
            }
            tail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1)
            remain = l1;
        if (l2) {
            tail->next = l2;
            remain = l2;
        }
        while (overflow && remain) {
            if (remain->val + overflow > 9) {
                remain->val = (remain->val + overflow) % 10;
            } else {
                remain->val += overflow;
                overflow = 0;
            }
            tail = remain;
            remain = remain->next;
        }
        if (overflow)
            tail->next = new ListNode(1);
        return head;
    }
};