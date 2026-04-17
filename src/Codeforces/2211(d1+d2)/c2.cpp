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
	vector<int> a(n), b(n);
	for (auto &e : a) {
		cin >> e;
	}
	for (auto &e : b) {
		cin >> e;
	}
	vector<vector<int>> a_buk(k), b_buk(k);
	for (int i = 0; i < n; i ++) {
		a_buk[i % k].push_back(a[i]);
		b_buk[i % k].push_back(b[i]);
	}
	bool ok = true;
	for (int i = 0; i < k; i ++) {
		int siz = a_buk[i].size();
		bool ok1 = ranges::count(a_buk[i], a_buk[i][0]) == siz;
		if (ok1) {
			ranges::sort(b_buk[i]);
			int c1 = ranges::count(b_buk[i], -1);
			int c2 = ranges::count(b_buk[i], b_buk[i].back());
			if (c1 + c2 == siz) {
				b[i] = b_buk[i].back();
			}
			ok1 &= (c1 == siz || c1 + c2 == siz);
		}
		bool ok2 = true;
		for (int j = 0; j < siz; j ++) {
			ok2 &= (b_buk[i][j] == -1 || a_buk[i][j] == b_buk[i][j]);
		}
		if (!ok1 && ok2) {
			b[i] = a[i];
		}
		ok &= (ok1 || ok2);
	}
	map<int, int> cnta, cntb;
	for (int i = 0; i < k; i ++) {
		cnta[a[i]] ++;
		cntb[b[i]] ++;
	}
	int sum = 0;
	for (auto [e, c] : cnta) {
		ok &= (c >= cntb[e]);
		sum += (c - cntb[e]);
	}
	ok &= (cntb[-1] == sum);
	if (ok) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
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