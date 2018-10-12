#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
 };
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
    ListNode* addTwoNumbers(ListNode* n1, ListNode* n2) {
        while(n1->next != NULL){
            cout << n1->val;
            n1 = n1->next;
        }
        while(n2->next != NULL){
            cout << n2->val;
            n2 = n2->next;
        }
    }
};

int main(){
    ListNode *n1 = new ListNode,*n2 = new ListNode;
    n1->next = NULL;
    n2->next = NULL;
    Solution solve;
    ListNode *headN1,*headN2;
    int x, format;
    headN1 = n1;
    headN2 = n2;
    string str;
    getline(cin,str);
    for(int i=1; i<str.size()-1;i++){
        if(str[i] != ','){
            n1->val = str[i];
            n1->next = new ListNode; 
            n1 = n1->next;
        }
    }
    getline(cin,str);
    for(int i=1; i<str.size()-1;i++){
        if(str[i] != ','){
            n2->val = str[i];
            n2->next = new ListNode; 
            n2 = n1->next;
        }
    }
    solve.addTwoNumbers(headN1,headN2);
    return 0;
}