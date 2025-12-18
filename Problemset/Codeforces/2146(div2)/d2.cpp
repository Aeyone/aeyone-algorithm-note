#include <bits/stdc++.h>
using namespace std;

using i64 = long long;


void solve() {
	int l, r;
	cin >> l >> r;
	int mx = r;
	vector<int> a(r - l + 2);
	map<int, int> vis;
	while(mx > l){
		int d = (1 << ((int)log2(mx) + 1)) - 1;
		for(int i = mx; i >= max(l, d - mx); i --){
			int x = d - i;
			// cout << "idx = " << i - l << '\n';
			// cout << "n = " << r - l + 1 << '\n';
			if(d - i >= l){
				a[i - l + 1] = x;
			}else{
				while(x < l || vis[x]){
					x += (1 << ((int)log2(x) + 1));
				}
				a[i - l + 1] = x;
				vis[x] = true;
			}
		}
		mx = d - mx - 1;
	}
	i64 sum = 0;
	for(int i = 1; i <= r - l + 1; i ++){
		sum += (a[i] | (i + l - 1));
	}
	cout << sum << '\n';
	for(int i = 1; i <= r - l + 1; i ++){
		cout << a[i] << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}