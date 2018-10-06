/* https://uva.onlinejudge.org/external/5/p558.pdf */

#include<bits/stdc++.h>
using namespace std;


#define INF 2147483647
						
int main(){
	int c, n, m,x,y,t;
	vector<int> dist;
	bool hasNegative = false;
	pair <int, int> v;
	vector< vector< pair<int,int> > > AdjList;
	cin >>c;
	for(int C = 0;C<c;C++){
		hasNegative = false;
		cin >> n >>m;
		dist = vector<int>(n,INF);
		dist[0] =0;
		AdjList.assign(n,vector< pair<int,int> >());
		for(int w = 0; w<m;w++){
			cin >> x >> y >> t;
			AdjList[x].push_back(make_pair(y,t));
		}
		for(int i =0; i< n-1; i++){	//relax all E edges V-1 times
			for(int u = 0; u < n; u++){ //these two loops = O(E), overall O(VE)
				for(int j = 0; j < (int)AdjList[u].size();j++){
					v = AdjList[u][j];	//record SP spanning here if needed
					dist[v.first] = min(dist[v.first], dist[u] + v.second);
				
				}
			}
		}
		for(int u =0; u< n;u++){ //one more pass to check
			for(int j = 0; j< (int)AdjList[u].size();j++){
				v = AdjList[u][j];
				if(dist[v.first] > dist[u] + v.second){
					hasNegative = true;
					break;
				}
			}
		}
		if(hasNegative){
			hasNegative = false;
			cout << "possible\n";
		}else{
			cout << "not possible\n";
		}
	}
return 0;
}