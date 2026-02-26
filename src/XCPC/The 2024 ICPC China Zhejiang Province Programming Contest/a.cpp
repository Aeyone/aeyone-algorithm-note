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
	vector<pair<string, int>> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i].first >> a[i].second;
	}
	vector<int> cnt(n, 1);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (i == j) {
				continue;
			}
			cnt[i] += (a[j].second > a[i].second);
		}
	}
	string res;
	for (int i = 0; i < n; i ++) {
		string s = a[i].first;
		if (s.size() <= cnt[i]) {
			continue;
		}
		res += s.substr(0, s.size() - cnt[i]);
	}
	res[0] -= ('a' - 'A');
	cout << "Stage: " << res << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}