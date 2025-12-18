#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	if(n % 4 == 0){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	vector<int> res(32);
	res[31] = 1;
	bool ok = (n & 1);
	if(ok)
		res[0] = -1;
	for(int i = 1; i < 31; i ++){
		if(n >> i & 1){
			if(ok)
				res[i - 1] = 1;
			ok = true;
		}
		res[i] = -1;
	}
	int ans = 0;
	for(int i = 0; i < 32; i ++){
		// ans += (1 << i) * res[i];
		cout << res[i] << ' ';
		if(i > 0 && (i + 1) % 8 == 0)
			cout << '\n';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}