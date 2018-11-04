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