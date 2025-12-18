#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	int cnt = 0;
	while(x >> cnt & 1)
		cnt ++;

	vector<int> res;
	int ans = 0;
	for(int i = 0; res.size() < n && i < 1 << cnt; i ++){
		res.push_back(i);
		ans |= i;
	}

	if(ans != x){
		while(res.size() >= n)
			res.pop_back();
		res.push_back(x);
	}
	while(res.size() < n)
		res.push_back(0);

	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}