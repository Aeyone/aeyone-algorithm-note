#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int, int>> v;
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && s[l] == s[r]) {
			r ++;
		}
		v.push_back({(s[l] == '1'), r - l});
	}
	int ans = count(s.begin(), s.end(), '1');
	if (v.size() == 1 && v.back().first == 0) {
		ans = v.back().second / 3 + (v.back().second % 3 != 0);
		cout << ans << '\n';
		return;
	}
	if (v.back().first == 0) {
		ans += v.back().second / 3 + (v.back().second % 3 == 2);
	}
	v.pop_back();
	if (v.size() && v.front().first == 0) {
		ans += v.front().second / 3 + (v.front().second % 3 == 2);
	}
	for (int i = 1; i < v.size(); i ++) {
		ans += (v[i].second / 3);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}