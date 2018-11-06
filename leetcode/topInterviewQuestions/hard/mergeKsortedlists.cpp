/* https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> pq;
        ListNode* head = new ListNode(0);
        ListNode* first = head;
        ListNode* pointer;
        for (int i = 0; i < lists.size(); i++) {
            pointer = lists[i];
            while (pointer != nullptr) {
                pq.push(-pointer->val);
                pointer = pointer->next;
            }
        }    
        while (!pq.empty()) {
            first -> next = new ListNode(-pq.top());
            pq.pop();
            first = first -> next;
        }
        return head->next;
    }
};

/*Using mergeTwoLists */

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
            return nullptr;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            head = mergeTwoSortedLists(head, lists[i]);
        }
        return head;
    }
    
private:
    ListNode* mergeTwoSortedLists(ListNode* L1, ListNode* L2) {
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while (L1 != nullptr && L2!= nullptr) {
            if (L2->val > L1->val) {
                dummy->next = L1;
                dummy = dummy->next;
                L1 = L1->next;
            } else {
                dummy->next = L2;
                dummy = dummy->next;
                L2 = L2->next;
            }
        }
        if (L1 == nullptr) {
            dummy->next = L2;
        } else {
            dummy->next = L1;
        }
        return head->next;
    }
};