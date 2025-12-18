#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;

void solve() {
	int n;
	cin >> n;
	vector<array<i64, >> pos(n);
	for(int i = 0; i < n; i ++)
		cin >> pos[i][0] >> pos[i][1];

	if(n == 1){
		cout << 1 << '\n';
		return;
	}
	int l = 0, d = 0, r = 0, u = 0;
	for(int i = 0; i < n; i ++){
		int x = pos[i][0], y = pos[i][1];
		if(pos[l][1] > y)
			l = i;
		if(pos[d][0] > x)
			d = i;
		if(pos[r][1] < y)
			r = i;
		if(pos[u][0] < x)
			u = i;
	}

	auto cost = [&](int idx)-> i64{
		// cout << idx << "!!!\n";
		int ll, dd, rr, uu;
		ll = dd = rr = uu = (idx == 0 ? 1 : 0);
		for(int i = 0; i < n; i ++){
			if(i == idx)
				continue;
			int x = pos[i][0], y = pos[i][1];
			if(pos[ll][1] > y)
				ll = i;
			if(pos[dd][0] > x)
				dd = i;
			if(pos[rr][1] < y)
				rr = i;
			if(pos[uu][0] < x)
				uu = i;
		}
		i64 res = (abs(pos[ll][1] - pos[rr][1]) + 1) * (abs(pos[dd][0] - pos[uu][0]) + 1);
		// cout << abs(pos[l][1] - pos[r][1]) + 1 << " " << (abs(pos[d][0] - pos[u][0]) + 1) << "@\n";
		// cout << ll << " " << dd << " " << rr << " " << uu << '\n';
		if(res == n - 1)
			res += min((abs(pos[ll][1] - pos[rr][1]) + 1) , (abs(pos[dd][0] - pos[uu][0]) + 1));
		return res;
	};

	i64 ans = 1e18;
	ans = min(ans, cost(l));
	ans = min(ans, cost(d));
	ans = min(ans, cost(r));
	ans = min(ans, cost(u));

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}