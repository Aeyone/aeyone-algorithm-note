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
	vector<int> a(n + 2), b(n + 2);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i ++) {
		int x;
		cin >> x;
		b[x] = true;
		a[0] = a[n + 1] = a[x];
	}
	b[0] = b[n + 1] = true;

	int sum = 0, mx = 0;
	for (int l = 0, r = 0; l <= n; l = r) {
		int cnt = (a[l] != a[l - 1]);
		while (r <= n && b[l] == b[r]) {
			r ++;
			cnt += (a[r] != a[r - 1]);
		}
		if (!b[l]) {
			sum += cnt;
			mx = max(mx, cnt);
		}
	}
	cout << max(mx, sum / 2) << '\n';
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