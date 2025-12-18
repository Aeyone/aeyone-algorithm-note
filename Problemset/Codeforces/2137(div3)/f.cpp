#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	for(int i = 0; i < n; i ++)
		cin >> b[i];

	vector<vector<int>> st(n, vector<int>(30));
	for(int i = 0; i < n; i ++)
		st[i][0] = a[i];

	for(int p = 1; n >> p > 0; p ++)
		for(int i = 0; i + (1 << p) <= n; i ++)
			st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		
	auto query = [&](int l, int r)->int{
		int p = log2(r - l + 1);
		return max(st[l][p], st[r -  (1 << p) + 1][p]);
	};

	i64 ans = 0;
	for(int i = 0; i < n; i ++){
		if(a[i] == b[i]){
			ans += (i64)(i + 1) * (n - i);
		}else{
			int l = 0, r = i - 1, j = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(query(mid, i - 1) >= max(a[i], b[i]))
					j = mid, l = mid + 1;
				else
					r = mid - 1;
			}
			if(j != -1)
				ans += (i64)(j + 1) * (n - i);
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}