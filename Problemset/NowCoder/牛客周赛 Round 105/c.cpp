#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	if(k & 1){
		cout << -1 << '\n';
		return;
	}
	int cnt = k / 2;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(cnt > 0 && i == j){
				cout << 1;
				cnt --;
			}else
				cout << 0;
		}
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}