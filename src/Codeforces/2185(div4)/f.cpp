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
	int n, q;
	cin >> n >> q;
	vector<int> a(1 << n);
	for (int i = 0; i < 1 << n; i ++) {
		cin >> a[i];
	}
	vector<int> sk((2 << n) + 1);
	auto dfs = [&](auto &&self, int u)->int{
		if (u >= 1 << n) {
			sk[u] = a[u ^ (1 << n)];
		} else {
			sk[u] = self(self, u << 1) ^ self(self, u << 1 | 1);
		}
		return sk[u];
	};
	dfs(dfs, 1);
	while (q --) {
		int idx, v;
		cin >> idx >> v;
		idx --;
		idx ^= 1 << n;
		int ans = 0, cur = v;
		for (int i = 0; idx >> i > 1; i ++) {
			if (sk[idx >> i ^ 1] > cur || (cur == sk[idx >> i ^ 1] && (idx >> i & 1))) {
				ans += 1 << i;
			}
			cur ^= sk[idx >> i ^ 1];
		}
		cout << ans << '\n';
	}
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