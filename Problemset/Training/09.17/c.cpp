#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int l = 1, r = n, x1 = 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(n / mid > m)
			x1 = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	int x = min(x1, n - m * k);

	int cur = 0;
	vector<int> res(n);
	k = max(k, x);
	for(int i = 0; i < k; i ++){
		res[i] = cur;
		cur = (cur + 1) % x;
	}
	for(int i = k; i < n; i ++){
		res[i] = res[i - k];
	}
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