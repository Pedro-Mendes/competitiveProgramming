/* https://br.spoj.com/problems/DOBRA/ */

#include<iostream>
#include <string>
#include <cstdio>
#include <queue>
typedef long long ll;
using namespace std;


int main(){
	int N, eq, anterior, aux, count = 0;
	cin >> N;
	while(N!=-1){
		count++;
		anterior = 0;
		for(int d = 0; d< N; d++){
			aux  = (2 * anterior) + 1;
			anterior = aux;
		}
		eq = (anterior * 4) + 4 + (anterior * anterior); 
		cout << "Teste " << count << endl << eq << endl << endl;			
		cin >> N;
	}	


return 0;
}
