#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), c1(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	vector<i64> s(n + 1);
	for(int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + a[i], c1[i] = c1[i - 1] + (a[i] == 1);

	while(q --){
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		if(l == r){
			cout << "NO" << '\n';
			continue;
		}
		int cnt = c1[r] - c1[l - 1];
		i64 sum = s[r] - s[l - 1];
		if(sum >= 2 * len || sum - (len - cnt) >= 2 * cnt)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}
