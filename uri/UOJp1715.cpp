/* https://www.urionlinejudge.com.br/repository/UOJ_1715.html */

#include<bits/stdc++.h>
using namespace std;
int main(){
	vector < vector<int> > AdjList;
	int n,m,x,sum=0;
	cin >> n >> m;
	AdjList.assign(n,vector <int> ());
	for(int i = 0; i<n;i++){
		for(int j = 0; j< m;j++){
			cin >> x;
			if(x!=0){
				AdjList[i].push_back(1);
			}
		}
		if(AdjList[i].size() == m)
			sum++;
	}
	cout << sum << endl;

return 0;
}