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
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	vector<int> fa(n + 2);
	fa[n + 1] = n + 1;
	for (int i = n; i >= 1; i --) {
		fa[i] = (a[i] > 1 ? i : fa[i + 1]);
	}

	auto find = [&](auto &&self, int x)-> int {
		while (fa[x] != x) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	};

	while (m --) {
		int x;
		cin >> x;
		int ans = 0;
		while (x <= n) {
			if (a[x] > 1) {
				ans ++;
				int to = x + a[x];
				a[x] --;
				if (a[x] == 1) {
					fa[x] = find(find, x + 1);
				}
				x = to;
				continue;
			}
			int to = find(find, x);
			ans += to - x;
			x = to;
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}
