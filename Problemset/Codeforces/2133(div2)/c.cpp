#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> d(n + 1);
	int cur = 0;
	for(int i = 1; i <= n; i ++){
		cout << "? " << i << ' ' << n << ' ';
		for(int j = 1; j <= n; j ++)
			cout << j << ' ';
		cout << '\n';
		cout.flush();

		int x;
		cin >> x;
		cur = max(cur, x);
		d[x].push_back(i);
	}
	vector<int> path = {d[cur][0]};
	while(cur > 1){
		cur --;
		bool ok = false;
		for(auto e : d[cur]){
			cout << "? " << path.back() << ' ' << 2 << ' ' << path.back() << ' ' << e << '\n';
			cout.flush();
			int x;
			cin >> x;
			if(x == 2){
				path.push_back(e);
				ok = true;
				break;
			}
		}
		if(!ok)
			break;
	}
	cout << "! ";
	cout << path.size() << ' ';
	for(auto e : path)
		cout << e << ' ';
	cout << '\n';
	cout.flush();
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	// ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}