#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + m + 1), b(n + m + 1), res(n + m + 1);
	for(auto &e : a)
		cin >> e;
	for(auto &e : b)
		cin >> e;

	i64 sum = 0;
	int t1 = n, t2 = m;
	int pg = n + m, ts = n + m;
	for(int i = 0; i < n + m; i ++){
		if(pg == n + m && t1 == 0 && a[i] > b[i])
			pg = i;
		if(ts == n + m && t2 == 0 && b[i] > a[i])
			ts = i;

		if(t1 > 0 && t2 > 0){
			if(a[i] > b[i])
				t1 --, sum += a[i], res[i] = 0;
			else
				t2 --, sum += b[i], res[i] = 1;
		}else if(t1 > 0){
			t1 --, sum += a[i], res[i] = 0;
		}else if(t2 > 0){
			t2 --, sum += b[i], res[i] = 1;
		}
	}
	i64 tmp = sum;
	for(int i = 0; i < n + m; i ++){
		if(res[i] == 0)
			sum -= a[i], sum += a[pg], sum -= (pg == n + m ? 0 : b[pg] - b[n + m]);
		if(res[i] == 1)
			sum -= b[i], sum += b[ts], sum -= (ts == n + m ? 0 : a[ts] - a[n + m]);
		cout << sum << ' ';
		sum = tmp;
	}
	cout << sum << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}