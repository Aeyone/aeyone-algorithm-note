#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

int query(int u, int v) {
	cout << "? " << u << ' ' << v << endl;
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> tot;
	for (int i = 1; i < n; i += 2) {
		int x = query(i, i + 1);
		if (x) {
			tot.push_back({i, i + 1});
		}
	}
	if (tot.size() > 1) {
		cout << "! 1" << endl;
		return;
	}
	if (tot.size() == 0) {
		bool ok = true;
		for (int i = 1; i <= 3; i ++) {
			ok &= query(i, n);
		}
		if (ok) {
			cout << "! 2" << endl;
		} else {
			cout << "! 1" << endl;
		}
	} else {
		auto [u, v] = tot[0];
		int cnt = 0;
		int ans = -1;
		int ok = 1;
		for (int i = 1; i <= n; i ++) {
			if (i == u || i == v) continue;
			if (cnt == 2) break;
			int x = query(u, i);
			ok &= x;
			cnt ++;
			if (cnt == 1 && x == 0) {
				break;
			}
			if (cnt == 2 && x == 0) {
				cout << "! 1" << endl;
				return;
			}
		}
		if (ok) {
			cout << "! 2" << endl;
		} else {
			cnt = 0;
			ok = 1;
			for (int i = 1; i <= n; i ++) {
				if (i == u || i == v) continue;
				if (cnt == 2) break;
				ok &= query(v, i);
				cnt ++;
			}
			if (ok) {
				cout << "! 2" << endl;
			} else {
				cout << "! 1" << endl;
			}
		}
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