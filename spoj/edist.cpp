/* https://www.spoj.com/problems/EDIST/ */

#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector< vector<int> > matrix, int n, int m){
	  for (int i = 0; i <= m+1; ++i){
  		for (int j = 0; j<= n+1; ++j){
  		cout << matrix[i][j] << " ";
  		}
  		cout << endl;
  	}
}

int minP(int a, int b, int c){
	return min(min(a,b),c);
}

int LevenshteinDistance(string s, string t){
  // for all i and j, d[i,j] will hold the Levenshtein distance between
  // the first i characters of s and the first j characters of t
  // note that d has (m+1)*(n+1) values
  int m,n,substitutionCost = 0;
  m = s.length();
  n = t.length();
  int matrix[m+1][n+1];
 
  // source prefixes can be transformed into empty string by
  // dropping all characters
  for (int i = 0; i <= m; ++i){
  	    matrix[i][0] = i;
  }
  // target prefixes can be reached from empty source prefix
  // by inserting every character
  for (int i = 0; i <= n; ++i){
  	    matrix[0][i] = i;
  }

  for (int j = 1; j <= n; ++j){
  	for (int i = 1; i <= m; ++i){
  		if (s[i-1] != t[j-1]){
  			matrix[i][j] = minP(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1] + 1);
  		}else{
        matrix[i][j] =  matrix[i-1][j-1];
      }
  	}
  }
  return matrix[m][n];
}
int main(){
	int T;
	cin >> T;
	string s,t;
	for (int i = 0; i < T; ++i){
		cin >> s >> t;
		cout << LevenshteinDistance(s,t) << endl;
	}
	
	return 0;
}