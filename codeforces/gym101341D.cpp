/* http://codeforces.com/gym/101341/problem/D */

#include<bits/stdc++.h>
using namespace std;

int mdc(int num1, int num2){
  int r = num1%num2;
  if(r == 0)
    return num2;
  mdc(num2,r);
}



int main(){
  int n, x,y, m=0;
  string answ = "NO";
  cin >> n >> x;
  for(int i =0 ;i < n;i++){
    cin >> y;
    m = mdc(m, y);
    if(x%m == 0){
      answ = "YES";
    }
  }
  //cout << m << endl;
  cout << answ << endl;





return 0;
}