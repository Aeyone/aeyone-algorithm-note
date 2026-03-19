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

	auto dfs = [&](this auto &&self, int l, int r, int base)-> int {
		auto L = a.begin() + l, R = a.begin() + r + 1;
		int mn = *min_element(L, R); // 贪心选择最小值 其余的递归找
		int res = mn - base;
		for (int i = l, j = l; i <= r; i = j) {
			while (j <= r && (a[i] == mn) == (a[j] == mn)) {
				j ++;
			}
			if (a[i] > mn) {
				res += self(i, j - 1, mn);
			}
		}
		return min(res, r - l + 1);
	};
	cout << dfs(0, n - 1, 0) << '\n';;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}