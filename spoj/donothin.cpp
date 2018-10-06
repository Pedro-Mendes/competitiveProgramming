/* https://www.spoj.com/problems/DONOTHIN/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,c,first;
  long long sum;
  cin >> n >> m;
  while(n!=-1 && m!=-1){
    sum = 0;
    cin >> first;
    sum += (n)*first;
    for (int i = 1; i < n; ++i)
    {
      cin >> c;
      sum += (n-i)*c;
    }
    sum *=m;
    cout << sum << endl;

    cin >> n >> m;
  }

  return 0;
}