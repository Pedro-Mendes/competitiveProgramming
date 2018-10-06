/* https://www.urionlinejudge.com.br/repository/UOJ_1228.html */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
	int n,x,found,count=0;
	vector<int> original,after;
	while(cin >> n){
		count = 0;
		found = 0;
		original.clear();
		after.clear();
		for(int i =0;i<n;i++){
			cin >> x;
			original.push_back(x);
		}
		for(int i =0;i<n;i++){
			cin >> x;
			after.push_back(x);
		}	
		for(int i =0;i<n;i++){
			for(int j =0;j<n;j++){
				if(after[j] == original[i]){
					for(int k =0;k<i;k++){
						for(int q =0;q<j;q++){
							if(original[k] == after[q]){
								found = 1;	
								break;
							}
						
						}
						if(!found){
							count++;
							found = 0;
						}
						found = 0;
					}
				}
			}
		}
	
	
	cout << count << endl;
	
	
	}

return 0;
}
