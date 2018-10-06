/* https://br.spoj.com/problems/PARPROX/ */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	double answ = 2000001,x,y;
	pair<int, int> p;
	vector< pair<int, int> > pts;
	pts.clear();
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		pts.push_back(make_pair(x,y));
		for (int i = 0; i < pts.size(); ++i)
		{
			if (pts[i].first != x && pts[i].second!= y)
			{
				answ = min(answ, sqrt((x-pts[i].first)*(x-pts[i].first) + (y-pts[i].second)*(y-pts[i].second)));
			}
		}
	}

	cout << setprecision(3) << fixed <<answ << endl;

return 0;
}