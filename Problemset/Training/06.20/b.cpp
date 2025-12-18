#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
vector<i64> num;

void init(){
	i64 x = 1;
	for(int i = 2; x * i <= 2e12; i ++)
		x *= i, num.push_back(x);
}

void solve() {
	i64 n;
	cin >> n;

	int ans = 1e9;
	for(int i = 0; i < 1 << num.size(); i ++){
		int tmp = i, cnt = 0;
		i64 sum = 0;
		for(int j = 0; i >> j > 0; j ++){
			if((i >> j) & 1)
				cnt ++, sum += num[j];
		}
		i64 x = n - sum;
		if(x < 0)
			continue;
		while(x)
			x -= (x & -x), cnt ++;
		ans = min(ans, cnt);
	}

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	init();
	while (_ --)
		solve();
}