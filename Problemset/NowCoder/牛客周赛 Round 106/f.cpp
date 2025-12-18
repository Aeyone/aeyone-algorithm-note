#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;

	vector<vector<int>> st(n, vector<int>(22));
	for(int i = 0; i < n; i ++)
		st[i][0] = a[i];
	
	for(int p = 1; n >> p > 0; p ++)
		for(int i = 0; i + (1 << p) <= n; i ++)
			st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);

	auto query = [&](int l, int r)->int{
		int p = log2(r - l + 1);
		return max(st[l][p], st[r - (1 << p) + 1][p]);
	};
	int res = 0;
	for(int i = 0; i < n - 1; i ++){
		int l = i + 1, r = n - 1, ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(query(i + 1, mid) >= a[i])
				ans = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		if(ans != -1 && a[ans] != a[i] && ans != i + 1)
			res ++;
	}
	for(int i = n - 1; i > 0; i --){
		int l = 0, r = i - 1, ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(query(mid, i - 1) >= a[i])
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		if(ans != -1 && a[ans] != a[i] && ans != i - 1)
			res ++;
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}