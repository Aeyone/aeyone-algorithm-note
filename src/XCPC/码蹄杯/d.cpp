#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 10007;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	i64 ans = 0;
	for (auto &e : a) {
		cin >> e;
		ans += e;
	}
	while (q --) {
		int x;
		cin >> x;
		if (x != 1 && ans > 0) {
			ans = 0;
			for (auto &e : a) {
				e = (e / x);
				ans += e;
			}
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}