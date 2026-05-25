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
	vector<int> a(n);
	map<int, int> mp1, mp2;
	int tg = 0;

	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		mp1[a[i]] ++;
		tg = __gcd(tg, a[i]);
	}
	mp2 = mp1;

	auto run1 = [&](map<int, int>& mp, int x)-> void {
		int c0 = mp[0], c1 = mp[1];
		int tot = n - c0 - c1;
		mp.clear();
		if (x == 1) {
			if (tot + c1 > 0) mp[0] = tot + c1;
			if (c0 > 0) mp[2] = c0;
		} else {
			if (tot + c1 > 0) mp[0] = tot + c1;
			if (c0 > 0) mp[1] = c0;
		}
	};

	auto run2 = [&](map<int, int>& mp, int x)-> void {
		map<int, int> cur;
		for (auto [e, c] : mp) {
			cur[__gcd(e, x)] += c;
		}
		mp = cur;
	};

	vector<array<int, 2>> tot(m);
	for (auto &[c, x] : tot) {
		cin >> c >> x;
	}

	string tmp;
	bool ok = false;
	for (int l = 0, r = 0; l < m; l = r) {
		while (r < m && tot[l][0] == tot[r][0]) {
			r ++;
		}
		tmp += char('0' + tot[l][0]);
		ok |= (tot[l][0] == 0 && r - l > 1);
	}

	set<string> ck = {"0", "1", "2", "10", "12", "02", "102"};

	ok |= ck.find(tmp) == ck.end();

	if (ok) {
		cout << "Yes" << '\n';
		return;
	}

	for (auto [c, x] : tot) {
		if (c == 1) run1(mp1, x), run1(mp2, x);
		else if (c == 2) run2(mp1, x), run2(mp2, x);
		else if (c == 0) {
			run1(mp1, x);
			run2(mp2, x);
		}
	}
	cout << ((mp1.size() == 1 || mp2.size() == 1) ? "Yes" : "No") << '\n';
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