#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	map<int, int> cnt;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	int ans = 0;
	for(auto [_ , e] : cnt)
		if(e >= 2)
			ans ++;

	for(int i = 1; i <= n; i ++)
		if(cnt[a[i]] >= 2)
			a[i] = i;
	
	a[0] = 0, a[n + 1] = inf;
	int l = 1;
	for(int i = 1; i <= n; i ++){
		if(a[i] <= a[i - 1]){
			ans += (i - l), l = i;
			if(a[i] < i)
				a[i] = i, ans ++;
		}
		if(a[i] == i)
			l = i + 1;
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