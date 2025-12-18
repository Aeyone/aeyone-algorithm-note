#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cnt1(n), cnt0(n);
	if(s[0] == '1')
		cnt1[0] = 1;
	else
		cnt0[0] = 1;
	for(int i = 1; i < n; i ++){
		cnt1[i] = cnt1[i - 1] + (s[i] == '1');
		cnt0[i] = cnt0[i - 1] + (s[i] == '0');
	}

	int ans = inf;
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			for(int k = j + 1; k < n - 1; k ++){
				int res1 = (cnt1[i] + (cnt0[j] - cnt0[i]) + (cnt1[k] - cnt1[j]) + (cnt0[n - 1] - cnt0[k]));
				int res2 = (cnt0[i] + (cnt1[j] - cnt1[i]) + (cnt0[k] - cnt0[j]) + (cnt1[n - 1] - cnt1[k]));
				ans = min(ans, min(res1, res2));
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}