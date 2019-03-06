/*https://leetcode.com/problems/palindrome-linked-list
git@Pedro-Mendes*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *start, *mid, *prev, *next;
        prev = nullptr;
        start = head;
        mid = head;
        //Finding the middle element
        while (start) {
            if (start->next) {
                mid = mid->next;
                start = start->next->next;
            } else {
                start = start->next;
            }
        }
        //reversing the second half
        while (mid) {
            next = mid->next;   //storing the next node
            mid->next = prev;   //reversing the order
            prev = mid;         //repositioning both prev and mid to move to the next position
            mid = next;
        }
        //Comparison element by element
        mid = prev;
        while(mid) {
            if (head->val != mid->val)
                return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
};

//Note: when has an even number of elements it returns the second repeated character in the middle
/* https://leetcode.com/problems/palindrome-linked-list
git@Pedro-Mendes */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*O(n) time and space complexity*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        int size;
        while(head != nullptr) {
            values.push_back(head->val);
            head = head -> next;
        }
        size = values.size();
        for (int i = 0; i < size/2; i++) {
            if(values[i] != values[size-1-i])
                return false;
        }
        return true;
    }
};
