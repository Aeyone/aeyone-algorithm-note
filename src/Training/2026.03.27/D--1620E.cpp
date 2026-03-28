#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*
*	倒推，维护当前每种数字的真实颜色，把x染色成y，就把x的真实颜色染成y的真实颜色
*/

void solve() {
	int q;
	cin >> q;
	vector<array<int, 3>> que(q);
	for (auto &[c, x, y] : que) {
		cin >> c >> x;
		y = 0;
		if (c == 2) {
			cin >> y;
		}
	}
	const int N = 5e5 + 1;
	vector<int> col(N), a;
	ranges::iota(col, 0);
	for (int i = q - 1; i >= 0; i --) {
		auto [c, x, y] = que[i];
		if (c == 1) {
			a.push_back(col[x]);
		} else {
			col[x] = col[y];
		}
	}
	ranges::reverse(a);
	for (auto e : a) {
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}