/* https://leetcode.com/problems/remove-duplicates-from-sorted-list
git@Pedro-Mendes */

class Solution {
public:
    void eliminate(ListNode* head){
        if(head==nullptr)
            return;
        if(head->next!=nullptr){
            if(head->next->val == head->val){
                head->next = head->next->next;
                eliminate(head);
            }else{
                eliminate(head->next);
            }
        }
        return;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy->next;
        eliminate(first);
        return dummy->next;
    }
};