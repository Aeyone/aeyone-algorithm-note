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
	int n, m, q;
	cin >> n >> m >> q;
	multiset<int> dx = {n}, dy = {m};
	set<int> x = {0, n}, y = {0, m};

	auto run = [&](set<int>& p, multiset<int>& dis, int pos)-> void {
		auto r = p.lower_bound(pos);
		auto l = prev(r);
		int len = *r - *l;
		dis.erase(dis.find(len));
		int lenL = pos - *l, lenR = *r - pos;
		dis.insert(lenL);
		dis.insert(lenR);
		p.insert(pos);
	};

	while (q --) {
		int c, e;
		cin >> c >> e;

		if (c == 1) {
			run(x, dx, e);
		} else {
			run(y, dy, e);
		}
		cout << 1ll * *(dx.rbegin()) * (*dy.rbegin()) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}