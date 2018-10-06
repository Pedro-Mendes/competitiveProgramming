/* https://br.spoj.com/problems/DAMA/ */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
	int x1,y1,x2,y2, achou=0;
	while(cin >> x1 >> y1 >> x2 >> y2 && x1!=0 && y1!=0 && x2!=0 && y2!=0){
		achou = 0;
		if(x1 == x2 && y1 == y2){ //if in same position
			cout << 0 << endl;
			achou = 1;
			continue;
		}else if((x1==x2 || y1==y2)){	//if in same line or column
			cout << 1 << endl;
			achou = 1;
			continue;
		}else{
			for(int i =1; i< 8;i++){	//if in diagonal
				//cout << "(" << x1-i << "," << y1-i << ")"<<  " "<<  "(" << x1-i << "," << y1+i << ")"<< " "<< "(" << x1+i << "," << y1-i << ")"<< " "<< "(" << x1+i << "," << y1+i << ")"<< endl; 
				if((x1-i==x2 && y1-i == y2) || (x1+i==x2 && y1+i == y2) || (x1-i==x2 && y1+i == y2) || (x1+i==x2 && y1-i == y2)){
					cout << 1 << endl;
					achou = 1;
					break;
				}
			}
		}
		if(!achou){	//if not found in any of the ifs
			cout << 2 << endl;
		}



	}


return 0;
}
