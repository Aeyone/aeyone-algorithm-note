#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int cnt = 1;
	vector<int> res;
	while(n){
		int t = (n % 10) * cnt;
		if(t != 0)
			res.push_back(t);
		cnt *= 10;
		n /= 10;
	}
	cout << res.size() << '\n';
	for(int e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}