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
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 1), b(n + 1), idxa(n + 1), idxb(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		idxa[a[i]] = i;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
		idxb[b[i]] = i;
	}

	vector<int> w(n + 1);

	auto modify = [&](int idx)-> int {
		int res = w[idx];
		w[idx] = (idxa[b[idx]] - idxa[b[idx - 1]] - 1 + n) % n;
		return w[idx] - res;
	};

	i64 ans = 0;
	for (int i = 1; i <= n; i ++) {
		modify(i);
		ans += w[i];
	}

	cout << ans << '\n';
	while (d > 1) {
		int c, x, y;
		cin >> c >> x >> y;
		if (c == 1) {
			int p = a[x], q = a[y];
			swap(idxa[p], idxa[q]);
			swap(a[x], a[y]);
			int i = idxb[p], j = idxb[q];
			ans += modify(i) + modify(j);
			if (i < n) ans += modify(i + 1);
			if (j < n) ans += modify(j + 1);
		} else {
			int p = b[x], q = b[y];
			swap(idxb[p], idxb[q]);
			swap(b[x], b[y]);
			int i = idxb[p], j = idxb[q];
			ans += modify(i) + modify(j);
			if (i < n) ans += modify(i + 1);
			if (j < n) ans += modify(j + 1);
		}
		cout << ans << '\n';
		d --;
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