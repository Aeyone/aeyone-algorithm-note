#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k, mx = 0;
	cin >> n >> k;
	vector<int> a(n), m(n);
	for(auto &e : a)
		cin >> e, mx = max(mx, e);

	m[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i --)
		m[i] = max(a[i], m[i + 1] + 1);

	auto check = [&](int x, int u)->bool{
		i64 sum = 0;
		for(int i = u; i < n - 1; i ++){
			if(a[i] >= x)
				break;
			sum += (x - a[i]), x --;
		}
		if(sum <= k)
			return true;
		else
			return false;
	};

	for(int i = 0; i < n - 1; i ++){
		int l = a[i], r = m[i], ans = a[i];
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid, i))
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		mx = max(mx, ans);
	}
	cout << mx << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}