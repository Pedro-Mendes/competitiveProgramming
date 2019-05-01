#include<bits/stdc++.h>
using namespace std;

int binarySearchCeil(const vector<int> &solution, int l, int r, int target, int &nextVal, const vector<int> &input) {
    if (l > r)
        return nextVal;
    int mid = l + (r-l)/2;
    if (input[solution[mid]] >= target){
        nextVal = mid;
        return binarySearchCeil(solution, l, mid-1, target, nextVal, input);
    } else { //solution[mid] < target
        return binarySearchCeil(solution, mid+1, r, target, nextVal, input);
    }
}

int main () {
    vector<int> input;
    vector<int> solution;
    map<int,int> redirect;
    int n,x,length = 1, indexNextLargerNum,nextVal;
    cin >> n;
    if (n == 0)
        return 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        input.push_back(x);
    }
    solution.push_back(0);
    //redirect[0] = -1;
    for(int i = 1; i < n; i++) {
        cout << input[i] << "        ";
        if (input[solution[length-1]] < input[i]) {
            solution.push_back(i);
            // redirect[i] = solution[length-1] + 1; //adding 1 so that we wont have to compare with null values in the map (which are values never initialized)
            length++;
        } else {
            indexNextLargerNum = binarySearchCeil(solution,0,length-1,input[i],nextVal, input);
            cout << "nextVal = " << indexNextLargerNum << "        ";
            solution[indexNextLargerNum] = i;
            // if (indexNextLargerNum-1 > 0) {
            //     redirect[i] = solution[indexNextLargerNum-1]+1;
            // } else {
            //     redirect[i] = -1;   
            // }
        }
        for (int i = 0; i < length; i++) {
            cout << solution[i] << " ";
        }
        cout << endl;
    }
    
    cout << "length = " << length;
    return 0;
}