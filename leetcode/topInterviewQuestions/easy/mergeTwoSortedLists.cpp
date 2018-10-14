class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL,*temp, *tail;
        while(l1 != NULL || l2 != NULL) {
            temp = new ListNode(0);
            if(l1!=NULL && l2==NULL) {
                cout << "Only L1" << endl;
                temp->val = l1->val;
                temp->next = NULL;
                if(head == NULL) {
                    head = temp;
                    tail = temp;
                }
                tail->next = temp;
                tail = tail->next;
                l1 = l1->next;
            }else if(l2!=NULL && l1==NULL) {
                cout << "Only L2" << endl;
                temp->val = l2->val;
                temp->next = NULL;
                if(head == NULL) {
                    head = temp;
                    tail = temp;
                }
                tail->next = temp;
                tail = tail->next;
                l2 = l2->next;
            }else{
                cout << "Both" << endl;
                if(l2->val > l1->val){
                    temp->val = l1->val;
                    temp->next = NULL;
                    
                    if(head == NULL) {
                        head = temp;
                        tail = temp;
                    }
                    
                    tail->next = temp;
                    tail = tail->next;
                    
                    temp = new ListNode(0);
                    
                    temp->val = l2->val;
                    temp->next = NULL;
                    tail->next = temp;
                    tail = tail->next;
                }else{
                    temp->val = l2->val;
                    temp->next = NULL;
                    
                    if(head == NULL) {
                        head = temp;
                        tail = temp;
                    }
                    
                    tail->next = temp;
                    tail = tail->next;
                    
                    temp = new ListNode(0);

                    temp->val = l1->val;
                    temp->next = NULL;
                    tail->next = temp;
                    tail = tail->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return head;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().mergeTwoLists(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}