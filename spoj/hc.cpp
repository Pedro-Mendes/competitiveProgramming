/* https://www.spoj.com/problems/HC/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, n,answ=0,x;
	string player,last;
	cin >> T;
	stack <int> q;
	for (int i = 0; i < T; ++i){
		cin >> n;
		for (int i = 0; i < n; ++i){
			cin >> player;
			if (player == "hhb"){
				q.push(0);
			}else{
				q.push(1);
			}
		}
		answ = q.top();
		q.pop();
		//cout << "answ= " << answ << endl;
		while(!q.empty()){
			x = q.top();
			q.pop();
			//cout << "x= " << x << endl;
			answ = ((1-x)*answ + (1-answ)*x);
			//cout << "answ= " << answ << endl << endl;
		}
		if (answ == 0){
			cout << "hhb\n";
		}else{
			cout <<"lxh\n";
		}
	}
	
return 0;
}