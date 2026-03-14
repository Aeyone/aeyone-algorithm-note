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
	int n, k;
	cin >> n >> k;
	vector<i64> a, b, p, q;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (i & 1) {
			b.push_back(x);
		} else {
			a.push_back(x);
		}
	}
	auto run = [&](vector<i64> &a, vector<i64> &tar)->void {
		int m = a.size();
		for (int mask = 0; mask < 1 << m; mask ++) {
			i64 sum = 0;
			for (int i = 0; i < m; i ++) {
				if (mask >> i & 1) {
					sum += a[i];
				}
			}
			tar.push_back(sum);
		}
	};
	run(a, p);
	run(b, q);
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	i64 ans = 0;
	for (i64 e : p) {
		i64 tar = k - e;
		int l = lower_bound(q.begin(), q.end(), tar) - q.begin();
		int r = upper_bound(q.begin(), q.end(), tar) - q.begin();
		ans += (r - l);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}