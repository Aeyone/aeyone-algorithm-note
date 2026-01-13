#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2), vis(n + 2);
	queue<int> q;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] == 2){
			q.push(i);
		}
	}
	int ans = 0;
	while(q.size()){
		int x = q.front();
		q.pop();
		if(vis[x]){
			continue;
		}
		vis[x] = true;
		ans ++;

		int l = x, r = x;
		while(l >= 1 && a[l] != 0){
			l --;
			vis[l] = true;
		}
		while(r <= n && a[r] != 0){
			r ++;
			vis[r] = true;
		}
	}
	vis[n + 1] = true;
	for(int l = 1, r = 1; l <= n; l = r){
		if(vis[l]){
			r ++;
			continue;
		}
		vis[l] = true;
		ans ++;

		while(r <= n && a[r + 1] == 1){
			r ++;
			vis[r] = true;
		}
		if(a[l] != 0){
			vis[r + 1] = true;
		}
		r ++;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}