#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 1000000007
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), vis(n);
	for(int i = 0; i < n; i ++){
		cin >> b[i];
		b[i] = a[i] = m - b[i];
	}
	map<array<int, 2>, int> seg;
	bool ok = true;
	while(ok){
		for(int l = 0, r = 0; l < n; l = r){
			if(a[l] == 0){
				r ++;
				continue;
			}
			while(r < n && a[r] != 0){
				a[r ++] --;
			}
			seg[{l, r}] ++;
		}
		ok = false;
		for(int i = 0; i < n; i ++){
			ok |= (a[i] > 0);
		}
	}
	i64 ans = 1;
	for(int i = 1; i < n; i ++){
		if(b[i] == b[i - 1] && !vis[i]){
			ans = ans * (b[i] + 1) % MOD;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}