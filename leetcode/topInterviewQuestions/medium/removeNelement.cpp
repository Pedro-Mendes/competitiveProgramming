/* https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/ 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0, count=0;
        ListNode* dummy = new ListNode(0);
        ListNode* first = dummy;
        dummy->next = head;
        if(first == nullptr)
            return nullptr;
        while(first->next != nullptr){
            size+=1;
            first = first->next;
        }
        if(size==0)
            return nullptr;
        size -= n;
        first = dummy;
        while(size>0){
            size--;
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }
};