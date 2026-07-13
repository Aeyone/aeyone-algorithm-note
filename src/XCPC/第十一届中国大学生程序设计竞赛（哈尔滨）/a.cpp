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
	int L, R;
	cin >> L >> R;
	vector<vector<array<int, 2>>> g(100);
	vector<int> in(100);
	int lsz = __lg(L), rsz = __lg(R);
	int idx = 0;

	if (lsz == rsz) {
		for (int i = lsz; i >= 0; i --, idx ++) {
			if ((L >> i & 1) == (R >> i & 1)) g[idx].push_back({idx + 1, (L >> i & 1)});
			else break;
			in[idx + 1] ++;
		}		
	}

	int cur = idx;
	if (L != R) {
		for (int i = 68; i < 99; i ++) {
			g[i].push_back({i + 1, 0});
			g[i].push_back({i + 1, 1});
			in[i + 1] += 2;
		}

		auto push = [&](int &p, int x, int u)-> void {
			if (p > 0) {
				g[u].push_back({cur + 1, x});
				in[cur + 1] ++;
				cur ++;
			} else {
				g[u].push_back({99, x});
				in[99] ++;
			}
			p --;
		};

		int lp = lsz - idx, rp = rsz - idx;

		push(lp, (L >> lp & 1), idx);
		while (lp >= 0) {
			int x = (L >> lp & 1);
			if (!x) {
				g[cur].push_back({99 - lp, 1});
				in[99 - lp] ++;
			}
			push(lp, x, cur);
		}

		push(rp, (R >> rp & 1), idx);
		while (rp >= 0) {
			int x = (R >> rp & 1);
			int p = 99 - rp + (!x), cnt = max(x, rsz - lsz);
			while (p < 100 && cnt --) {
				g[cur].push_back({p, !x});
				if (!x) g[cur].push_back({p, 0});
				in[p] ++;
				p ++;
			}
			push(rp, x, cur);
		}
	}
	vector<int> v, u(100);
	for (int i = 0; i <= cur; i ++) {
		u[i] = v.size();
		v.push_back(i);
	}
	int p = 68;
	while (p < 100 && !in[p]) {
		for (auto [e, _] : g[p]) {
			in[e] --;
		}
		p ++;
	}
	for (int i = p; i < 100; i ++) {
		u[i] = v.size();
		v.push_back(i);
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i ++) {
		int e = v[i];
		cout << g[e].size() << ' ';
		for (auto [c, x] : g[e]) {
			cout << u[c] + 1 << ' ' << x << ' ';
		}
		cout << '\n';
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