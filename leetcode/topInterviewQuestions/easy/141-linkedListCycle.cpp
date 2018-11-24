/* https://leetcode.com/problems/linked-list-cycle/
git@Pedro-Mendes */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        ListNode* knownPointer = head;
        ListNode* previous;
        head = head->next;
        while (head != nullptr && head != knownPointer) {
            previous = head;
            head = head->next;
            previous->next = knownPointer;
        }
        if(head == nullptr)
            return false;
        return true;
    }
};