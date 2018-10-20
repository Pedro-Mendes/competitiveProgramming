/* https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy->next;
        ListNode* last = dummy;
        while(first!=nullptr){
            if(first->val == val){
                last->next = first->next;
            }else{
                last = first;
            }
            first = first->next;
        }
        return dummy->next;
    }
};