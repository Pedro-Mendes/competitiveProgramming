/* https://leetcode.com/problems/add-two-numbers/ 
git@Pedro-Mendes*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
 };

 class Solution {
public:
    ListNode* addTwoNumbers(ListNode* n1, ListNode* n2) {
        int n1Value = 0, n2Value=0,answer=0,n3Value=0;
        bool existsNode = true;
        ListNode *n3, *headN3 = NULL, *temp;
        while(n1 != NULL){
            n1Value = (n1Value*10)+(n1->val);
            n1 = n1->next;  
        }
        cout << "n1 ="  << n1Value << endl;
        while(n2 != NULL){
            n2Value = (n2Value*10)+n2->val;
            n2 = n2->next;
        }
        cout << "n2 ="  << n2Value << endl;
        answer = n1Value + n2Value;
        //cout << "answer" << answer << endl;
        while(existsNode){
            temp = new ListNode;
            temp->val = answer%10;
            temp->next = NULL;
            //cout << temp->val << endl;
            if(headN3==NULL){
                headN3 = temp;
                n3 = temp;
            }else{
                n3->next = temp;
                n3 = n3->next;
            }
            answer/=10;
            if(answer/10 + answer%10 <= 0){
                existsNode = false;
            }
        }
        //cout << "end of vals\n";
        temp = headN3;
        while(temp != NULL){
            n3Value = (n3Value*10)+temp->val;
            cout << temp->val << endl;
            temp = temp->next;
        }
        cout << n3Value << endl; 
        return headN3;
    }
};

int main(){
    ListNode *n1,*n2;
    Solution solve;
    ListNode *headN1,*headN2;
    int x, format;
    headN1 = NULL;
    headN2 = NULL;
    string str;
    getline(cin,str);
    for(int i=1; i<str.size()-1;i++){
        if(str[i] != ','){
            n1 = new ListNode;
            n1->val = str[i]-'0';
            n1->next = headN1;
            headN1 = n1;
        }
    }
    getline(cin,str);
    for(int i=1; i<str.size()-1;i++){
        if(str[i] != ','){
            n2 = new ListNode;
            n2->val = str[i]-'0';
            n2->next = headN2;
            headN2 = n2;
        }
    }
    solve.addTwoNumbers(headN1,headN2);
    return 0;
}   