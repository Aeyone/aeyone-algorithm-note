#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int c0 = count(s.begin(), s.end(), '0');
	int c1 = count(s.begin(), s.end(), '1');
	int cnt = (max(c0, c1) - min(c0, c1)) / 2;
	if(k - cnt < 0 ||(k - cnt) % 2 == 1 || k - cnt > min(c0, c1)){
		cout << "NO\n";
		return;
	}
	if((k - cnt) % 2 == 0)
		cout << "YES\n";
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}