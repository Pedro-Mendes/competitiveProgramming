/* https://br.spoj.com/problems/BOTAS/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,c,eC,dC;
	char l;
	map < int,vector<char> > shoes;
	while(cin >> n){
		shoes.clear();
		c = 0;
		for(int i =0; i< n;i++){
			cin >> m >> l;
			shoes[m].push_back(l);
		}

		
			for(int i =0; i< shoes.size();i++){
				dC = 0;
				eC = 0;
				for(int j = 0; j< shoes[i].size();j++){
					if(shoes[i][j] == 'E'){
						eC++;
					}
					else if(shoes[i][j] == 'D'){
						dC++;
					}
				}
				c+= min(dC,eC);
			}		
		/*
			if((shoes[m] != l && shoes[m] == 'D') || (shoes[m] != l && shoes[m] == 'E')){
				c++;
				shoes[m] = 'X';
			}else{
				shoes[m] = l;
			}
			*/


		cout << c << endl; 


	}

return 0;
}
