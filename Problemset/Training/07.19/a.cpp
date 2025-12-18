#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;

	vector<int> f(n + 1, 1);//位置a_i作为开头出现的次数
	i64 sum = 0, h = 0, ans = 0;
	for(int i = 0; i < n; i ++){
		sum += a[i];
		ans += (i + 1);
		while(sum > x)
			sum -= a[h], ans -= f[h], f[i + 1] += f[h ++];
	}
	cout << ans << '\n';
	//把问题分成从1 ~ i,2 ~ i,...,(i-1) ~ i这些区间里面有哪些会变成0，有哪些会小于等于x
	//加入一个数时，保证sum<=x成立，所以需要删去头部的a_h
	//假设一个数都不删，那该数的贡献就为i
	//如果需要删除数，在删去这个数的时候需要减去这些数作为开头出现的次数
	//然后在删数的同时也代表着，只有加入当前a_i时 才出现sum > x
	//因此同时需要更新下一个位置的数以开头出现的次数 也就是加入a_i之后导致区间和为0的数量
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}