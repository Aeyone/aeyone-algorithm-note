#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 k, x;
	cin >> k >> x;
	int i = 0;
	while(!(x >> i & 1))
		i ++;

	vector<int> res;
	for(i = i + 1; i <= k; i ++){
		if(x >> i & 1){
			res.push_back(2);
		}else{
			res.push_back(1);
		}
	}
	cout << res.size() << '\n';
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}