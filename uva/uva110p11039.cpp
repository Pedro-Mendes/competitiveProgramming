/* https://uva.onlinejudge.org/external/110/p11039.pdf */

#include<iostream>
#include <string>
#include <cstdio>
#include <queue>
typedef long long ll;
using namespace std;

int main(){
	priority_queue < pair <int, string> > pq;
	int p_cases, n_floors,f, count;
	pair<int , string> floor;
	string previous;
	cin >> p_cases;

	for(int i = 0; i< p_cases; i++){
		count = 1;
		cin >> n_floors;
		//cout << "n_floors = " << n_floors<< endl;
		for(int j=0; j<n_floors; j++){
			cin >> f;
			if(f<0){
				pq.push(make_pair(f*(-1), "vermelho" ));
			}else{
				pq.push(make_pair(f, "azul" ));
			}
		}
		floor = pq.top();
		previous  = ((string) floor.second).c_str();
		//cout << "previous = " << previous << endl;
		//cout << "count = " << count<< endl;
		pq.pop();
		while(!pq.empty()){
			floor = pq.top();
			//cout <<  "floor.second = " << ((string)floor.second).c_str() << endl;
			if(((string)floor.second).c_str() != previous){
				count++;
				previous = ((string)floor.second).c_str();
				//cout << "previous = " << previous << endl;
				//cout << "count = " << count<< endl;
			}
			
			pq.pop();
		}
		cout << count << endl;
	}
return 0;
}
