/* http://codeforces.com/problemset/problem/475/A */

#include<bits/stdc++.h>
using namespace std;

int main(){
string firstLine,secondLine,thirdLine,fourthLine,fifthLine,sixthLine;
firstLine = "+------------------------+";
secondLine = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
thirdLine = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
fourthLine = "|#.......................|";
fifthLine = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
sixthLine = "+------------------------+";
int ppl,k1=1,k2=1,k3=1,k4=1,k5=1;
char knext = '2';
cin >> ppl;
	while(ppl>0){
		if(secondLine[k2] == '#' && knext=='2'){
			secondLine[k2] = 'O';
			k2 +=2;
			knext = '3';
		}else if (thirdLine[k3] == '#' && knext=='3'){
			thirdLine[k3] = 'O';
			k3 +=2;
			if (k4 == 1)
			{
				knext = '4';
			}else{
				knext = '5';
			}
		}else if (fourthLine[k4] == '#' && knext=='4'){
			fourthLine[k4] = 'O';
			k4 += 2;
			knext='5';
		}else if (fifthLine[k5] == '#' && knext=='5'){
			fifthLine[k5] = 'O';
			k5 +=2;
			knext='2';
		}
		ppl--;
	}


cout << firstLine << endl;
cout << secondLine << endl;
cout << thirdLine << endl;
cout << fourthLine << endl;
cout << fifthLine << endl;
cout<< sixthLine << endl;
return 0;
}