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
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 2), pre(n + 1), suf(n + 2), tot = {1};
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector st(n + 1, vector<int>(21));
	for (int i = 1; i <= n; i ++) {
		st[i][0] = abs(a[i] - a[i + 1]);
	}
	for (int p = 1; p < 21; p ++) {
		for (int i = 1; i + (1 << p) <= n + 1; i ++) {
			st[i][p] = __gcd(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		}
	}

	auto query = [&](int l, int r)->int {
		if (l > r) {
			return 0;
		}
		int d = __lg(r - l + 1);
		return __gcd(st[l][d], st[r - (1 << d) + 1][d]);
	};

	for (int i = 1; i <= n; i ++) {
		pre[i] = __gcd(pre[i - 1], a[i]);
		if (pre[i] < pre[i - 1]) {
			tot.push_back(i);
		}
	}
	for (int i = n; i >= 1; i --) {
		suf[i] = __gcd(suf[i + 1], a[i]);
	}
	int ans = pre[n];
	for (int i = 1; i <= n; i ++) {
		int res = __gcd(a[i] + k, suf[i + 1]);
		for (auto idx : tot) {
			if (idx > i) {
				break;
			}
			ans = max(ans, __gcd(res, __gcd(pre[idx - 1], query(idx, i - 1))));
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