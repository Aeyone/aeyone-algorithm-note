#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<i64>> a(n, vector<i64>(n + 1)), s(n + 1, vector<i64>(n + 1));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++)
			cin >> a[i][j];

		for(int j = n - 1; j >= 0; j --)
			s[i][j] = s[i][j + 1] + a[i][j];
	}
	vector<int> cnt(n);
	for(int j = n - 1; j > 0; j --){
		for(int i = 0; i < n; i ++){
			if(s[i][j] != n - j)
				continue;
			cnt[n - j] ++;
		}
	}
	int ans = 0;
	for(int i = 1; i < n; i ++){
		bool ok = (cnt[i] > 0);
		for(int j = i - 1; j >= 1; j --){
			ok &= (cnt[i] && cnt[j] >= i - j + 1);
		}
		if(ok)
			ans ++;
		else
			break;
	}
	cout << ans + 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}