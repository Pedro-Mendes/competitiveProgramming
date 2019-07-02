/*https://leetcode.com/problems/flatten-nested-list-iterator
git@Pedro-Mendes*/

class NestedIterator {
private:
    stack<NestedInteger> s;
    vector<NestedInteger> innerList;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size()-1; i >= 0; i--) {
            s.push(nestedList[i]);
        }
    }

    int next() {                                                    
        int top;                                                                                                                           
        top = s.top().getInteger();
        s.pop();
        return top;
    }

    bool hasNext() {
        while(!s.empty() && !s.top().isInteger()) {
            innerList = s.top().getList();
            s.pop();
            for (int i = innerList.size()-1; i >= 0; i--) {
                s.push(innerList[i]);
            }    
        }
        if(!s.empty() > 0)
            return true;
        return false;
    }
};