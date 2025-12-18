#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> cnt;
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	if(n == 1){
		cout << 1 << '\n';
		return;
	}
	int ans = (n + 1) / 2;
	int l = n / 2 - 1, r = n / 2 + (n & 1); 
	int c1 = 0, c2 = 0;
	while(l >= 0){
		c1 += (cnt[a[l --]] >= 2);
	}
	while(r < n){
		c2 += (cnt[a[r ++]] >= 2);
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