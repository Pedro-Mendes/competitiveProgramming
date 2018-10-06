/* http://codeforces.com/problemset/problem/546/C */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, p1,p2, n_p1, n_p2, x,card1, card2,c=0;
	queue <int> q1; 
	queue <int> q2; 
	bool forever = false;
	std::map< pair<int, int>, int> m;
	cin >> n; //total de cards
	cin >> n_p1; 
	for (int i = 0; i < n_p1; ++i)
	{
		cin >> x;
		q1.push(x);
	}
	cin >> n_p2;
	for (int i = 0; i < n_p2; ++i)
	{
		cin >> x;
		q2.push(x);
	}
	while(q1.empty() == 0 && q2.empty() == 0) {
		card1 = q1.front();
		q1.pop();
		card2 = q2.front();
		q2.pop();
		//cout << "Carta do jogador 1 : " << card1<< endl;
		//cout << "Carta do jogador 2 : " << card2<< endl;
		m[make_pair(card1, card2)] += 1;
		if(m[ make_pair(card1, card2)] > (n*n)){
			forever = true;
			break;
		}
		if (card1 > card2)
		{
			//cout << "jogador 1 ganha esta rodada\n";
			q1.push(card2);
			q1.push(card1);
		}else{
			//cout << "jogador 2 ganha esta rodada\n";
			q2.push(card1);
			q2.push(card2);
		}
		c++;
	}

	if (forever)
	{
		cout << -1 << endl;
	}else{
		if (q1.empty())
		{
			cout << c << " " << 2 << endl;
		}else{
			cout << c << " " << 1 << endl;
		}
	}

return 0;
}