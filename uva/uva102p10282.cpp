/* https://uva.onlinejudge.org/external/102/p10282.pdf */

#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<string>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<int,int> ii ;
typedef vector<ii> vii;
typedef pair<string, string> ss;
typedef vector<ss> vss;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main(){
	vss dic;
	ss word;
	map< string, string > mapper;
	string cName, wName, c,w, input;
	vector<string> right, wrong, aux;
	int pos;
	while (getline(cin, input)){
	if (input.empty())
		break;
	pos = input.find_first_of(' ');
	cName = input.substr(0, pos);
	wName = input.substr(pos+1);
	mapper[wName] = cName;
	//cout << cName << endl;
	//cout << wName << endl;
	aux.push_back(wName);
	//right.push_back(cName);
	}
	while(cin >> w){
			c = mapper[w];
			if(c!=""){
			cout << c << endl;
		}else{
			cout << "eh" << endl;
		}
	}
return 0;
}

