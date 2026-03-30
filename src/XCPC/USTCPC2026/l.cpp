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
	s = " " + s;
	vector<int> pre(n + 3);
	for (int i = 1; i <= n + 1; i ++) {
		pre[i] += pre[i - 1] + (s[i] == 'o');
	}
	vector<pair<char, int>> v = {{'<', 0}};
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '<' || s[i] == '>') {
			v.push_back({s[i], i});
		}
	}
	v.push_back({'>', n + 1});
	int ans = 0;
	for (int i = 1; i < v.size(); i ++) {
		if (v[i - 1].first == '<' && v[i].first == '>') {
			ans = max(ans, pre[v[i].second] - pre[v[i - 1].second]);
		}
	}
	cout << pre[n] - ans << '\n';
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