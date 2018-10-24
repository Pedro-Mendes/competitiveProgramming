/* source: http://faculty.cse.tamu.edu/djimenez/ut/utsa/cs3343/lecture25.html 
recursive function to generate permutations */

#include<bits/stdc++.h>
using namespace std;

void swap (int v[], int i, int j) {
	int	t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void perm (int v[], int n, int i) {
	if (i == n) {
		for (int j=0; j<n; j++) printf ("%d ", v[j]);
		printf ("\n");
	} else
		for (int j=i; j<n; j++) {
			swap (v, i, j);
			perm (v, n, i+1);
			swap (v, i, j);
		}
}

int main(){
    int v[5] = {1,2,3,4};
    perm(v,4,0);
}