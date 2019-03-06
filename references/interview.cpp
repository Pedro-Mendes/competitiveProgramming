#include<bits/stdc++.h>
using namespace std;

/* input/output example

input:
 0  1  2  3  4    5
[2, 5, 3, 7, 10, 13] 

output:
 */

 /*
 First try

 vector<double> output;
    double sum=0;
    for(int i = 0; i < input.size(); i++ ){
	    sum = 0;
        if( i-N/2 < 0 || i+N/2 >= input.size() )
            continue;
	    sum+=input[i]
	for(int j = 1; j <= N/2; j++ ){
		sum += input[i+j] + input[i-j];		//sum=3 + 7 + 5 = 15
	}
	output.push_back(sum/N);			//output = [10,15,]
}

M -> vector size
N -> window size
O(M*N)

*/

/*********************************After interview*************************************/


//n=3, [2, 5, 3, 7, 10, 13] 
void solve(vector<double> input, int n, vector<double> output){		
	int sum = 0;
    for(int i = 0; i<n; i++){			
            sum += input[i]
    }					//sum = 10
    output.push_back((double)sum/n);	//output = [(double)(10)/3] = [3.3333...]
    for(int i = n; i<input.size(); i++){
        sum-= input[n-i];		//sum = 17
        sum += input[i];		//sum = 30
        output.push_back((double)sum/n); //output = [3.333…, 5, 6.666…,10]
    }
}
/**************************************************************************************/


int main(){
    vector<double> input;
    vector<double> output;
    int n, inputSize;
    double x;
    cin >> n;
    cin >> inputSize;
    for(int i = 0; i< inputSize; i++){
        cin >> x;
        input.push_back(x);
    }
    cout << "input: ";
    for(int i = 0; i< inputSize; i++)
        cout << input[i] << " ";
    solve(input,n,output);
    cout << endl;
    cout << "output: ";
    cout << fixed;
    cout << setprecision(2);
    for(int i = 0; i< output.size(); i++)
        cout << output[i] << " "; 
    cout << endl;
    return 0;
}