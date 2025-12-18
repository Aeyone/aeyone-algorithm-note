#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool ok = true;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		ok &= (i + 1 >= a[i]);
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	vector<int> ans(n, -1), vis(n + 1);
	vis[a.back()] = true;
	for(int i = 0; i < n - 1; i ++){
		vis[a[i]] = true;
		if(a[i] != a[i + 1]){
			ans[i + 1] = a[i];
		}
	}
	int cur = 0;
	for(int i = 0; i < n; i ++){
		while(vis[cur]){
			cur ++;
		}
		if(ans[i] == -1){
			cout << cur << ' ';
			vis[cur] = true;
		}else{
			cout << ans[i] << ' ';
		}
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}