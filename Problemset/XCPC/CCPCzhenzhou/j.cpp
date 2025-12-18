#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

void solve() {
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i <= 26; i ++){
		int sum = 0;
		for(int j = 0; j < s.size(); j ++){
			sum += cnt[(s[j] - 'A' + i) % 26];
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}