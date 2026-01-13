#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	bool ok = false;
	i64 sum = 0;
	int ans = 0, cc = 0;
	map<i64, int> mp;
	for(int i = 0; i < n; i ++){
		sum += a[i];
		ok |= (a[i] == 0);
		if(ok){
			if(a[i] == 0){
				int cnt = 0;
				for(auto [num, c] : mp)
					cnt = max(cnt, c);
				ans += cnt;
				mp.clear();
			}
			mp[sum] ++;
		}
		if(!ok && sum == 0)//要记得考虑没有0的情况
			cc ++;
	}
	int cnt = 0;
	for(auto [num, c] : mp)
		cnt = max(cnt, c);
	ans += (cnt + cc);
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