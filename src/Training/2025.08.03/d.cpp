#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> a(n), pre(n);
	vector<int> c(m);
	for(auto &[e, _] : a)
		cin >> e;
	for(auto &[_, e] : a)
		cin >> e;

	sort(a.begin(), a.end());
	map<int, int> mp;
	mp[a[0][0]] = a[0][0] - a[0][1];

	for(int i = 1; i < n; i ++){
		if(a[i][0] - a[i][1] < (-- mp.end())->second)
			mp[a[i][0]] = a[i][0] - a[i][1];
	}
	auto it = --mp.end();
	i64 ans = 0;
	for(auto &e : c){//注意到c[i]范围在1e9 而a[i]范围为1e6 则第一次操作就可以把c[i]减小至1e6级别
		cin >> e;
		if(e > it->first){
			int d = (e - it->first) / it->second;
			e -= (d + 1) * it->second;
			ans += 2 * (d + 1);
		}
	}
	int _n = it->first + 1;
	vector<int> f(_n);
	for(int i = 1; i < _n; i ++){//因此只需要先把c[i]控制在1e6范围
		int x = i;
		auto it = mp.upper_bound(x);
		if(it == mp.begin())
			continue;
		-- it; //<=x
		int d = (x - it->first) / it->second;
		x -= (d + 1) * it->second;

		f[i] = 2 * (d + 1) + f[x];//然后利用从小到大递推，把所有1e6范围的数的答案预处理出来
	}
	for(auto e : c)
		ans += f[e];

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}