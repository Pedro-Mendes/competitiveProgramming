/* http://codeforces.com/problemset/problem/822/A */

#include<bits/stdc++.h>
using namespace std;
int fat[14];

int main(){
	fat[0] = 1;
fat[1] = 1;
fat[2] = 2;
fat[3] = 6;
fat[4] = 24;
fat[5] = 120;
fat[6] = 720;
fat[7] = 5040;
fat[8] = 40320;
fat[9] = 362880;
fat[10] = 3628800;
fat[11] = 39916800;
fat[12] = 479001600;
	int a,b;
	cin >> a >> b;
	cout << fat[min(a,b)] << endl;
	return 0;
}