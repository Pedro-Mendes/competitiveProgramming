/* https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {             //1->2->3->4->5->NULL
        ListNode* dummy = new ListNode(0);          //d->0->null
        ListNode* tmp = nullptr;                    //tmp->null
        while (head != nullptr) {                
            dummy->val = head->val;                 //d->3->2->1->null
            tmp = new ListNode(0);                  //tmp->0
            tmp->next = dummy;                      //tmp->0->2->1
            dummy = tmp;                            //d->0->2->1
            head = head->next;
        }
        return dummy->next;
    }
};