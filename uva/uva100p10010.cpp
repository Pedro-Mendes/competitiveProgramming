/* https://uva.onlinejudge.org/external/100/p10010.pdf */

#include<bits/stdc++.h>
using namespace std;



int matrixQuery(string s, vector< vector<char> > v, int r, int c, int i, int j,int k, string direction){
	s[k] = tolower(s[k]);
	int answ;
	if (direction == "Horizontal"){
		if (i+1 <r){
			if (v[i+1][j] == s[k]){
				if(k == s.length()-1){
					return 1;
				}else{
					if(matrixQuery(s,v,r,c,i+1,j,k+1,direction)){
						return 1;
					}
				}
			}
		}
		if (i-1 >= 0){
			if (v[i-1][j] == s[k]){
				if(k == s.length()-1){
					return 1;
				}else{
					if(matrixQuery(s,v,r,c,i-1,j,k+1,direction)){
						return 1;
					}
				}
			}
		}
	}else if(direction == "Vertical"){
		if (j+1 < c){
			if (v[i][j+1] == s[k]){
				if(k == s.length()-1){
					return 1;
				}else{
					if(matrixQuery(s,v,r,c,i,j+1,k+1,direction)){
						return 1;
					}
				}
			}
		}
		if (j-1>=0){
			if (v[i][j-1] == s[k]){ 
				if(k == s.length()-1){
					return 1;
				}else{
					if(matrixQuery(s,v,r,c,i,j-1,k+1,direction)){
						return 1;
					}
				}
			}
		}
	}else if(direction == "Diagonal"){
		if (i+1 <r && j+1<c){
			if (v[i+1][j+1] == s[k]){
				if(k == s.length()-1){
					return 1;
				}else{
					if(matrixQuery(s,v,r,c,i+1,j+1,k+1,direction)){
						return 1;
					}
				}
			}
		}
		if (i-1 >=0 && j-1>=0){
			if (v[i-1][j-1] == s[k]){
				if(k == s.length()-1){
					return 1;
				}else{
					if(matrixQuery(s,v,r,c,i-1,j-1,k+1,direction)){
						return 1;
					}
				}
			}
		}
	}else{ //first time checking 
		if(matrixQuery(s,v,r,c,i,j,k,"Horizontal")){
			return 1;
		}else if(matrixQuery(s,v,r,c,i,j,k,"Vertical")){
			return 1;
		}else if(matrixQuery(s,v,r,c,i,j,k,"Diagonal")){
			return 1;
		}
	}
	return 0;
}

pair<int , int> matrixQuery_util(string s, vector< vector<char> > v, int r, int c){
	s[0] = tolower(s[0]);
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			if(v[i][j] == s[0] && matrixQuery(s,v,r,c,i,j,1,"search")){
					return make_pair(i,j);
			}
		}
	}
}




int main(){
	int t,m,n,q;
	char x;
	string s, blank;
	pair <int, int> p;
	vector< vector<char> > v;
	cin >> t;
	for (int k = 0; k < t; ++k){
		if (k>0){
			cout << endl;
		}
		cin >> m >> n;
		v = vector< vector<char> > (m, vector<char> (n));
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				cin >> x;
				v[i][j] = tolower(x);
			}
		}
		/*for (int i = 0; i < m; ++i){
			cout << v[i][0];
			for (int j = 1; j < n; ++j){
				cout << " " << v[i][j];
			}
			cout << endl;
		}*/

		cin >> q;
		for (int i = 0; i < q; ++i){
			cin >> s;
			p =  matrixQuery_util(s,v,m,n);
			cout << p.first+1 << " " << p.second+1 << endl;
		}
	}

	
return 0;
}