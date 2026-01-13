#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), cnt(n);
	for(int i = 0; i < m; i ++)
		cin >> a[i], cnt[a[i] - 1] ++;

	auto check = [&](int x)-> bool{
		int c1 = 0, c2 = 0;
		for(int i = 0; i < n; i ++){
			if(cnt[i] > x)
				c1 += cnt[i] - x;	
			else	
				c2 += (x - cnt[i]) / 2;
		}
		return c1 <= c2;
	};

	int l = 0, r = 2 * m, ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
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