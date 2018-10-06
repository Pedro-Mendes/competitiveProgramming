/* https://br.spoj.com/problems/ACIDO/ */

#include <bits/stdc++.h>

using namespace std;

bool link(char a, char b){
	if(a == 'B' && b == 'S') {return true;}
	if(a == 'S' && b == 'B') {return true;}
	if(a == 'C' && b == 'F') {return true;}
	if(a == 'F' && b == 'C') {return true;}
	return false;

}

void printInput(string input){
	for(int i =0;i<input.size();i++){
				cout << input[i];
			}
			cout << endl;

}

int main(){
	int lig;
	bool flag;
	string input;
	while(cin >> input){
		lig = 0;
		flag = true;
		while(flag){
			flag = false;
			for(int i =0;i<input.size()-1;i++){
				if(link(input[i],input[i+1])){
					input.erase(input.begin()+i);
					input.erase(input.begin()+i);
					//printInput(input);
					lig++;
					flag = true;
				}
				if(input.size()==0){flag = false; break;}
			}
		}
		cout << lig << endl;
	
	
	}




return 0;
}
