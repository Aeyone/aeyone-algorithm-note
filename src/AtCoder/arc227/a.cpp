#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	 int n;
	 cin >> n;
	 string a, b, c;
	 cin >> a >> b >> c;
	 vector<int> da, db, dc;
	 for (int i = 0; i < 2 * n; i ++) {
	 	if (a[i] == '1') da.push_back(i);
	 	if (b[i] == '1') db.push_back(i);
	 	if (c[i] == '1') dc.push_back(i);
	 }
	 vector<int> ans(n);
	 int sum = 0;
	 for (int i = 0; i < n; i ++) {
	 	vector<int> v = {da[i], db[i], dc[i]};
	 	sort(v.begin(), v.end());
	 	ans[i] = v[1];
	 	sum += (v[1] - v[0]);
	 	sum += (v[2] - v[1]);
	 }
	 cout << sum << '\n';
	 string s = string(2 * n, '0');
	 for (auto e : ans) s[e] = '1';
	 cout << s << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}