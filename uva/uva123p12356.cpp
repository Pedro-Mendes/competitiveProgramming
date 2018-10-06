/* https://uva.onlinejudge.org/external/123/p12356.pdf */

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
	int s,b,l,r;
	cin >> s >> b;
	vector<int> Ls, Rs;
	while(s!= 0 && b!=0){
		Ls.clear();
		Rs.clear();
		for(int i = 0; i<s+1 ; i++){
			Ls.push_back(i-1);
			Rs.push_back(i+1);
		}
		for(int i = 0; i<b ; i++){
			cin >> l >> r;
			
			if(Ls[l] == 0){
				cout << "* ";
				
			}else{
				cout << Ls[l] << " ";
			
			}
			if(Rs[r] == s+1){
				cout << "*\n";
			
			}else{
				cout << Rs[r] << endl;
			
			}
			
			Ls[Rs[r]] = Ls[l];
			Rs[Ls[l]] = Rs[r];
		}
	cout << "-\n";
	cin >> s >> b;
	}

return 0;
}

