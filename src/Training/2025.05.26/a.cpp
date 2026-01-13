#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

void solve() {
	vector<int> a(4);
	for(int i = 0; i < 4; i ++)
		cin >> a[i];

	int ok = 0;
	for(int i = 0; i < 4; i ++){
		vector<int> b;
		for(int j = 0; j < 4; j ++){
			if(i == j)
				continue;
			b.push_back(a[j]);
		}
		if(b[0] + b[1] > b[2] && b[0] + b[2] > b[1] && b[1] + b[2] > b[0])
			ok = max(ok, 2);
		else if(b[0] + b[1] == b[2] || b[0] + b[2] == b[1] || b[1] + b[2] == b[0])
			ok = max(ok, 1);
		else
			ok = max(ok, 0);
	}
	if(ok == 2)
		cout << "TRIANGLE" << '\n';
	else if(ok == 1)
		cout << "SEGMENT" << '\n';
	else
		cout << "IMPOSSIBLE" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}