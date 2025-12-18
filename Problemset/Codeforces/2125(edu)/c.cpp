#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 l, r;
	cin >> l >> r;
	auto f = [&](i64 x)->i64{
		i64 res = x;
		res -= (x / 2 + x / 3 + x / 5 + x / 7);
		res += (x / 6 + x / 10 + x / 14 + x / 15 + x / 21 + x / 35);
		res -= (x / 30 + x / 42 + x / 70 + x / 105);
		res += (x / 210);
		return res;
	};

	vector<int> a = {2, 3, 5, 7};
	auto get = [&](i64 x)->i64{
		i64 res = 0;
		for(int mask = 0; mask < (1 << 4); mask ++){
			i64 num = x;
			for(int i = 0; i < 4; i ++){
				if(mask >> i & 1)
					num /= a[i];
			}
			res += num * ((__builtin_popcount(mask) & 1) ? -1 : 1);
		}
		return res;
	};
	cout << get(r) - get(l - 1) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}