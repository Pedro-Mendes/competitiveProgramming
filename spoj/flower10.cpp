/* https://br.spoj.com/problems/FLOWER10/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	string input, word;
	int token;
	bool nope;
	char alit;
	while(getline(cin,input)){
		nope = false;
		token=1;
		if(input == "*")
			break;
		alit = input[0];
		
		while(!input.empty() && token!=-1){
			token = input.find_first_of(' ');
			word = input.substr(0, token);
			input = input.substr(token+1);
			//cout << word << endl;
			if(word[0] != tolower(alit) && word[0]!= toupper(alit)){
				nope = true;
				cout << "N\n";
				break;	
			}
		}
		if(!nope)
		cout << "Y\n";
	}


return 0;
}
