/* https://uva.onlinejudge.org/external/116/p11634.pdf */

#include<bits/stdc++.h>
using namespace std;

std::map<int, int> usedNumbah;

int main(){
	int x, c=0;
	bool cycle = true;
	cin >> x;
	while(x != 0){
		c = 0;
		cycle = true;
		usedNumbah.clear();
		usedNumbah[x] = 1;
		c = 1;
		while(cycle){
			x *= x;
			x /= 100;
			x %= 10000;
			if (usedNumbah[x] != 1) //if not yet mapped
			{
				c++;
				usedNumbah[x] = 1; //now mapped
			}else{ //if already mapped this means that the cycle restarted
				cout << c << endl;
				cycle = false;
				continue;
			}
		}
		cin >> x;
	}
}