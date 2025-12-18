#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 x;
	cin >> x;
	if(x == 1){
		cout << "Yes" << '\n';
		return;
	}
	vector<i64> num;
	for(int i = 2; i <= x / i; i ++)
		num.push_back((i64)i * i);

	for(int i = 0; i < (1 << num.size()) ;i ++){
		int cnt = 0;
		i64 res = 0;
		for(int j = 0; (i >> j) > 0; j ++)
			if((i >> j) & 1)
				cnt ++, res += num[j];
		if(res - cnt + 1 == x){
			cout << "Yes" << '\n';
			return;
		}
	}
	cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}