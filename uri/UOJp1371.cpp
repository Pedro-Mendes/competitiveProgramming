/* https://www.urionlinejudge.com.br/repository/UOJ_1371.html */

#include<bits/stdc++.h>
using namespace std;

int main(){
		int n;
		vector<int> doors;
		doors.clear();
		cin >> n;
				for(int i = 1; i<=sqrt(25000000);i++){
						doors.push_back(pow(i,2));
				}
		
	while(n!=0){		
	cout << doors[0];
	for(int i = 1; i <doors.size();i++){
		if(doors[i] <= n){
			cout <<" "<< doors[i] ;		
		}else{
			break;
		
		}

	}
	cout << endl;
	cin >> n;
	}

return 0;
}