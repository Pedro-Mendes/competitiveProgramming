/* https://uva.onlinejudge.org/external/104/p10452.pdf */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int main(){
	int p,x,startL,startC,endL,endC,m,n;
	int A_l, A_r, V_l, V_r,  O_l, O_r, H_l, H_r, E_l, E_r, I_l, I_r, end_l, end_r, start_l, start_r;
	char aux;
	cin >> p;
	for(int i =0; i<p;i++){
		cin >> m >> n;
		for(int j = 0; j<m;j++){
			for(int k = 0; k<n;k++){
					cin >> aux;
					if(aux == 'A'){
						A_l = j;
						A_r = k;
					}else if(aux == 'V'){
						V_l = j;
						V_r = k;
					}else if(aux == 'O'){
						O_l = j;
						O_r = k;
					}else if(aux == 'H'){
						H_l = j;
						H_r = k;
					}else if(aux == 'E'){
						E_l = j;
						E_r = k;
					}else if(aux == 'I'){
						I_l = j;
						I_r = k;
					}else if(aux == '@'){
						start_l = j;
						start_r = k;
					}else if(aux == '#'){
						end_l = j;
						end_r = k;
					}
			}
		}
			if(start_l - I_l){
				cout << "forth ";
			}else if(start_r - I_r < 0){
				cout << "right ";
			}else{
				cout << "left ";
			}
			if(I_l - E_l){
				cout << "forth ";
			}else if(I_r - E_r < 0){
				cout << "right ";
			}else{
				cout << "left ";
			}
			if(E_l - H_l){
				cout << "forth ";
			}else if(E_r - H_r < 0){
				cout << "right ";
			}else{
				cout << "left ";
			}
			if(H_l - O_l){
				cout << "forth ";
			}else if(H_r - O_r < 0){
				cout << "right ";
			}else{
				cout << "left ";
			}
			if(O_l -V_l){
				cout << "forth ";
			}else if(O_r - V_r < 0){
				cout << "right ";
			}else{
				cout << "left ";
			}
			if(V_l - A_l){
				cout << "forth ";
			}else if(V_r - A_r < 0){
				cout << "right ";
			}else{
				cout << "left ";
			}
			if(A_l - end_l){
				cout << "forth\n";
			}else if(A_r - end_r < 0){
				cout << "right\n";
			}else{
				cout << "left\n";
			}

	}

return 0;
}
