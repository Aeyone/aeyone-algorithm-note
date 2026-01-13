#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < n; i ++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	auto cnt = [&](i64 p, vector<int> &arr)->int{
		int l = 0, r = n - 1, ans = n;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(arr[mid] >= p)
				ans = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		return ans;
	};

	i64 ans = 0;
	for(auto e : a){
		int ca = cnt(e, a), cb = cnt(e, b);
		if(ca - cb <= k)
			ans = max(ans, (i64)(n - cb) * e);
	}
	for(auto e : b){
		int ca = cnt(e, a), cb = cnt(e, b);
		if(ca - cb <= k)
			ans = max(ans, (i64)(n - cb) * e);
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