/* https://leetcode.com/problems/merge-two-sorted-lists/ 
git@Pedro-Mendes*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL,*temp, *tail;
        while(l1 != NULL || l2 != NULL) {
            temp = new ListNode(0);
            if(l1!=NULL && l2==NULL) {
                //cout << "Only L1" << endl;
                temp->val = l1->val;
                temp->next = NULL;
                if(head == NULL) {
                    head = temp;
                    tail = temp;
                }else{
                    tail->next = temp;
                    tail = tail->next;
                }
                l1 = l1->next;
            }else if(l2!=NULL && l1==NULL) {
                //cout << "Only L2" << endl;
                temp->val = l2->val;
                temp->next = NULL;
                if(head == NULL) {
                    head = temp;
                    tail = temp;
                }else{
                    tail->next = temp;
                    tail = tail->next;
                }
                l2 = l2->next;
            }else{
                //cout << "Both" << endl;
                if(l2->val > l1->val){
                    temp->val = l1->val;
                    temp->next = NULL;
                    
                    if(head == NULL) {
                        head = temp;
                        tail = temp;
                    }else{
                        tail->next = temp;
                        tail = tail->next;
                    }
                    l1 = l1->next;
                }else{
                    temp->val = l2->val;
                    temp->next = NULL;
                    
                    if(head == NULL) {
                        head = temp;
                        tail = temp;
                    }else{
                        tail->next = temp;
                        tail = tail->next;
                    }
                    l2 = l2->next;
                }
            }
        }
        return head;
    }
};