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
	for (auto &e : a){
		cin >> e;
	}

	auto check = [&](int mex)-> bool {
		vector<int> vis(mex), b, c;
		for (int i = 0; i < n; i ++) {
			if (a[i] < mex && !vis[a[i]]) {
				vis[a[i]] = true;
			} else {
				b.push_back((a[i] + 1) / 2 - 1);
			}
		}
		for (int i = mex - 1; i >= 0; i --) {
			if (!vis[i]) {
				c.push_back(i);
			}
		}
		ranges::sort(b, greater<int>{});
		if (b.size() < c.size()) {
			return false;
		}
		bool ok = true;
		for (int i = 0; i < c.size(); i ++) {
			ok &= (b[i] >= c[i]);
		}
		return ok;
	};

	int l = 0, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid, l = mid + 1;
		} else {
			r = mid - 1;
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