/* https://www.urionlinejudge.com.br/repository/UOJ_1548.html */

#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m,pj,c,index,last_index;
	cin >> n;
	pair <int,int> par;   
	priority_queue < pair<int,int> > pq;
	for(int i = 0 ;i<n;i++){
		cin >> m;
		c = 0;
		index = 0;
		pq = priority_queue < pair<int,int> >();
		for(int j = 0; j<m;j++){
			cin >> pj;
			pq.push(make_pair(pj,j));
		}
		while(!pq.empty()){
			par = pq.top();
			pq.pop();
			if(par.second == index){
				c++;
			}
			index++;
		}
		cout << c << endl;
		
	}
	


return 0;
}
