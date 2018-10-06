/* https://br.spoj.com/problems/PRIMO/ */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
	int p;
	string answ = "sim";
	cin >> p;
	for(int i =2; i<p;i++){
		if(p%i==0){
			answ = "nao";
			break;
		}
	}	
	cout << answ << endl;
return 0;
}
