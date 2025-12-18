#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s;
	cin >> t;
	s = " " + s;
	t = " " + t;
	vector<int> l(m + 1);
	l[0] = 0;
	for(int i = 1; i <= m; i ++){
		for(int j = l[i - 1] + 1; j <= n; j ++){
			if(t[i] == s[j]){
				l[i] = j;
				break;
			}
		}
	}
	vector<int> r(m + 2);
	r[m + 1] = n + 1;
	for(int i = m; i >= 1; i --){
		for(int j = r[i + 1] - 1; j >= 1; j --){
			if(t[i] == s[j]){
				r[i] = j;
				break;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < m; i ++){
		ans = max(ans, r[i + 1] - l[i]);
	}
	// for(int i = 1; i <= m; i ++)
	// 	cout << l[i] << ' ' << r[i] << '\n';

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