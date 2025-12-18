#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	sort(a.begin(), a.end());

	if(n > 65){
		cout << "NO" << '\n';
		return;
	}
	bool ok = true;
	for(int i = 1; i < n; i ++){
		for(int j = i - 1; j >= 0; j --){
			ok &= ((a[i] ^ a[j]) >= a[i] + 1);
		}
	}
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}