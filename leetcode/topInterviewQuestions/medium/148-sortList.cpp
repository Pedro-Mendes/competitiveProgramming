class Solution {
private:
    void splitList(ListNode* head, ListNode** firstHalf, ListNode** secondHalf) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr) {
            fast = fast->next;
            if(fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *firstHalf = head;
        *secondHalf = slow->next;
        slow->next = nullptr;
    }
    
    ListNode* merge2SortedLists(ListNode* L1, ListNode* L2) {
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while(L1 != nullptr && L2 != nullptr) {
            if (L1->val > L2->val) {
                dummy->next = L2;
                dummy = dummy->next;
                L2 = L2->next;
            } else {
                dummy->next = L1;
                dummy = dummy->next;
                L1 = L1->next;
            }
        }
        if(L1) {
            dummy->next = L1;
            dummy = dummy->next;
        } else {
            dummy->next = L2;
            dummy = dummy->next;
        }
        return head->next;
    }
    
    void mergeSort(ListNode** head) {
        if(*head == nullptr)
            return;
        if((*head)->next == nullptr)
            return;
        ListNode *firstHalf, *secondHalf, *headRef = *head;
        splitList(headRef, &firstHalf, &secondHalf);
        mergeSort(&firstHalf);
        mergeSort(&secondHalf);
        *head = merge2SortedLists(firstHalf, secondHalf);
    }
public:
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head;
    }
};