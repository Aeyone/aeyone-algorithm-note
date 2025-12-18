#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	i64 sum = -((i64)n * k);
	for(int i = 0; i < n; i ++)
		cin >> a[i], sum += a[i];

	int idx = n - 1;
	i64 cur = (a[idx] - a[idx] / 2), ans = sum;
	a[idx] /= 2;
	while(idx >= 0){
		sum += (k - cur);
		ans = max(ans, sum);
		idx --, cur = 0;
		if(idx < 0)
			break;
		for(int i = idx; i < min(n, idx + 32); i ++){
			cur += (a[i] - a[i] / 2);
			a[i] /= 2;
		}
	}
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