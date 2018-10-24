/* References:
https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c/28698654
 */

/* 
To get all K-element combinations, you first pick initial element of a combination out of existing set of people,
 and then you "concatenate" this initial element with all possible combinations of K-1 people produced from elements 
 that succeed the initial element.

As an example, let's say we want to take all combinations of 3 people from a set of 5 people. Then all possible 
combinations of 3 people can be expressed in terms of all possible combinations of 2 people:

comb({ 1 2 3 4 5 }, 3) =
{ 1, comb({ 2 3 4 5 }, 2) } and
{ 2, comb({ 3 4 5 }, 2) } and
{ 3, comb({ 4 5 }, 2) }
Here's C++ code that implements this idea: */
/* 
#include <iostream>
#include <vector>

using namespace std;

vector<int> people;
vector<int> combination;

void pretty_print(const vector<int>& v) {
  static int count = 0;
  cout << "combination no " << (++count) << ": [ ";
  for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
  cout << "] " << endl;
}

void go(int offset, int k) {
  if (k == 0) {
    pretty_print(combination);
    return;
  }
  for (int i = offset; i <= people.size() - k; ++i) {
    combination.push_back(people[i]);
    go(i+1, k-1);
    combination.pop_back();
  }
}

int main() {
  int n = 5, k = 3;

  for (int i = 0; i < n; ++i) { people.push_back(i+1); }
  go(0, k);

  return 0;
}
 */

/*Using bitmask*/

#include <algorithm>
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

void comb(int N, int K)
{
    std::string bitmask(K, '1'); // K leading 1's
    bitmask.resize(N, '0'); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        /* for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) std::cout << " " << i+1;
        }
        std::cout << std::endl; */
        cout << bitmask << std::endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

int main()
{
    comb(3, 2);
}

/* 
Analysis and idea

The whole point is to play with the binary representation of numbers for example the number 7 in binary is 0111
So this binary representation can also be seen as an assignment list as such:
For each bit i if the bit is set (i.e is 1) means the ith item is assigned else not.
Then by simply computing a list of consecutive binary numbers and exploiting the binary representation 
(which can be very fast) gives an algorithm to compute all combinations of N over k.
The sorting at the end (of some implementations) is not needed. It is just a way to deterministicaly 
normalize the result, i.e for same numbers (N, K) and same algorithm same order of combinations is returned



*/