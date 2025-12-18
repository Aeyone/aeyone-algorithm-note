#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

void solve() {//一道比较不错的数学题
	int l, r;
	cin >> l >> r;
	i64 cnt = 0;
	while(l * (1 << (cnt + 1)) <= r){
		cnt ++;
	}
	auto find = [&](i64 x)->int{
		int L = l, R = r, res = l - 1;
		while(L <= R){
			int mid = (L + R) / 2;
			if(x * mid <= r)
				res = mid, L = mid + 1;
			else
				R = mid - 1;
		}
		return res;
	};
	i64 ans = ((find(1 << cnt) - l + 1) + cnt * (find((1 << (cnt - 1)) * 3) - l + 1)) % mod;
	cout << cnt + 1 << ' ' << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}