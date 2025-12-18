#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, m;
	cin >> n >> m;
	vector<int> a(n), c(n);
	map<int, i64> mp;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	i64 res = 0;
	for(auto [num, c] : mp){
		if(mp.find(num + 1) == mp.end()){
			res = max(res, min(c, m / num) * num);
			continue;
		}
		i64 R = m - min(m / num, c) * num;
		i64 cnt = min(R / (num + 1), mp[num + 1]);
		R = R - cnt * (num + 1);
		R = max(0ll, R - min(min(m / num, c), mp[num + 1] - cnt));//注意加一的数量不能超过当前num的数量
		res = max(res, m - R);
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}