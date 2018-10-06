/* https://www.spoj.com/problems/BANDW/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  bool sequence;
  int answ,sum;
  cin >> s >> t;
  while(s!= "*" && t != "*"){
    sum = 0;
    answ =0;
    sequence = true;
    for (int i = 0; i < s.length(); ++i)
    {
      if (s[i] != t[i] && sequence)
      {
        answ++;
        sequence = false;
      }
      if (s[i] == t[i])
      {
        sequence = true;
      }
    }
    cout << answ << endl;
    cin >> s >> t;
  }
  return 0;
}