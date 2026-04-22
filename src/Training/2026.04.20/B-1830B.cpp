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
	vector<int> a(n), b(n);
	set<int> st;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
		if (a[i] <= 2 * n / a[i]) {
			st.insert(a[i]);
		}
	}

	i64 ans = 0;
	for (auto e : st) {
		vector<int> pre(n + 1), tot(n + 1);
		for (int i = 0; i < n; i ++) {
			if (a[i] == e) {
				tot[b[i]] ++;
			}
		}
		for (int i = 0; i < n; i ++) {
			int x = a[i] * e - b[i];
			if (a[i] <= 2 * n / a[i]) {
				if (x >= 1 && x <= n) {
					ans += pre[x];
				}
				if (a[i] == e) {
					pre[b[i]] ++;
				}
			} else {
				if (x >= 1 && x <= n) {
					ans += tot[x];
				}
			}
		}
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