/* https://www.urionlinejudge.com.br/repository/UOJ_1606.html */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	int n,max_number,x;
	vector<int> repeated, original;
	while(cin >> n >> max_number){
		repeated.resize(max_number);
		repeated.clear();
		for(int i=0; i<n; i++){
			cin >> x;
			if(repeated[x-1] == 0){
				repeated[x-1] = 1;
				if(i == 0){
					cout << x;
				}else{
					cout << ' ' << x;
				}
			}
		}

		cout << endl;

	}

return 0;
}
