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
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 1;
	for (int i = 0; i < n; i ++) {
		for (int j = i; j >= 0; j --) {
			int num = 2 * a[i] - a[j];
			int idx = upper_bound(a.begin(), a.end(), num) - a.begin() - 1;
			if (a[idx] == num) {
				if (idx - i > i - j) {
					ans = max(ans, (i - j + 1) * 2);
				} else {
					ans = max(ans, (idx - i) * 2 + 1);
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