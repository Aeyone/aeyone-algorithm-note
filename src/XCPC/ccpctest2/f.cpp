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
	vector<int> a(n + 2);
	vector<array<int, 21>> st(n + 2);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		st[i][0] = a[i];
	}
	for (int p = 1; n >> p > 0; p ++) {
		for(int i = 1; i + (1 << p) <= n + 1; i ++){
			st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		}
	}

	auto query = [&](int l, int r)->int{
		int p = __lg(r - l + 1);
		return max(st[l][p], st[r - (1 << p) + 1][p]);
	};

	i64 ans = 0;
	for (int i = 1; i <= n; i ++) {
		auto f1 = [&](int l, int r)-> int {
			int R = r, ans = 0;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (query(mid, R) > a[i]) {
					ans = mid, l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			return ans;
		};

		auto f2 = [&](int l, int r)-> int {
			int L = l, ans = n + 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (query(L, mid) > a[i]) {
					ans = mid, r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			return ans;
		};

		int L1 = f1(1, i - 1);
		int L2 = 0;
		if (L1 != 0) {
			L2 = f1(1, L1 - 1);
		}

		int R1 = f2(i + 1, n);
		int R2 = n + 1;
		if (R1 != n + 1) {
			R2 = f2(R1 + 1, n);
		}

		if (L1 != 0) {
			int d = i - L1;
			ans += 1ll * d * (L1 - L2) * (R1 - i);
		}
		if (R1 != n + 1) {
			int d = R1 - i;
			ans += 1ll * d * (R2 - R1) * (i - L1);
		}
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