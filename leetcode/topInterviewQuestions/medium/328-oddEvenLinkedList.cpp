/*https://leetcode.com/problems/odd-even-linked-list/
git@Pedro-Mendes*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*O(N) time complexity and O(1) space complexity*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return head;
        ListNode *even = head, *odd = head->next, *headOdd = odd, *headEven = even;
        while (even->next && odd->next) {
            even->next = even->next->next;
            even = even->next;
            odd->next = odd->next->next;
            odd = odd->next;
        }
        even->next = headOdd;
        return headEven;
    }
};