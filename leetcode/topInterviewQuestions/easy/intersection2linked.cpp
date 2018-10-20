/* https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB==nullptr)
            return nullptr;
        int sizeA=0;
        int sizeB=0;
        ListNode* dummyA = new ListNode(0);
        dummyA->next = headA;
        ListNode* dummyB = new ListNode(0);
        dummyB->next = headB;
        
        ListNode* firstA = dummyA->next;
        ListNode* firstB = dummyB->next;
        
        while(firstA != nullptr){
            sizeA++;
            firstA = firstA->next;
        }
        firstA = dummyA->next;
        
        while(firstB != nullptr){
            sizeB++;
            firstB = firstB->next;
        }
        firstB = dummyB->next;
        
        while(sizeA>sizeB){
            sizeA--;
            firstA = firstA->next;
        }
        
        while(sizeB>sizeA){
            sizeB--;
            firstB = firstB->next;
        }
        
        if(firstA == firstB)
            return firstA;
        
        while(firstA!=nullptr && firstB!=nullptr){
            if(firstA->next == firstB->next && firstA->next!=nullptr)
                return firstA->next;
            firstA = firstA->next;
            firstB = firstB->next;
        }
        
        return nullptr;
    }
};