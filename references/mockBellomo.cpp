/*INPUT
Input = {[A,  A’,  A’’, A’’’],[B,  B’,  B’’],[C] }
Output = {
[A,B,C],   /
[A,B'',C], 
[A,B'',C],
[A',B,C],
[A',B'',C],
[A',B''',C],
[A'',B,C],
[A'',B',C],
[A'',B'',C],
[A''',B,C],
[A''',B',C],
[A''',B'',C]
}
*/
#include<bits/stdc++.h>
using namespace std;

void combination(vector< vector<string> > &solution, int index, vector<string> &step,const vector< vector<string> > &input, int k){
    if(k==0){
        solution.push_back(step);
        return;
    }
    for(int i=0; i<input[index].size();i++){
        step.push_back(input[index][i]);
        combination(solution,index+1,step,input,k-1);
        step.pop_back();
    }
    
}

int main(){

    vector< vector<string> > input;
    input.push_back(vector<string> ());
    input[0].push_back("A");
    input[0].push_back("A'");
    input[0].push_back("A''");
    input[0].push_back("A'''");
    input.push_back(vector<string> ());
    input[1].push_back("B");
    input[1].push_back("B'");
    input[1].push_back("B''");
    input.push_back(vector<string> ());
    input[2].push_back("C");
    vector<string> step;
    vector< vector<string> > solution;
    combination(solution,0,step,input,input.size());
    cout << "Input: " << endl;
    for(int i = 0; i<input.size();i++){
        for(int j=0; j<input[i].size();j++){
            cout << input[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Output:" << endl;
    for(int i = 0; i<solution.size();i++){
        for(int j=0; j<solution[i].size();j++){
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}



