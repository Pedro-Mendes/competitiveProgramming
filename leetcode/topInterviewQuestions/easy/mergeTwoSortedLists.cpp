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

/* Optimized solution O(1) space complexity and O(N) time complexity which N is the number of nodes*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while (l1!=nullptr && l2!=nullptr) {
            if (l1->val > l2->val) {
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            } else {
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
            }
        }
        if (l1 == nullptr)
            dummy->next = l2;
        if (l2 == nullptr)
            dummy->next = l1;
        return head->next;
    }
};